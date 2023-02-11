#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <assert.h>
#include <string>

#ifdef DEBUG
#include "debug.h"
#endif 

template<typename T> class RBTree {
 private:
  class RBTreeNode {
  public:
    enum Color {
      RED = 0,
      BLACK = 1,
    };
    enum Side {
      LEFT = 0,
      RIGHT = 1,
    };

    RBTreeNode (long long k, T * o, RBTree * t) :
    obj (o), key (k), color (RED), parent (NULL), tree (t) {
      this->link[LEFT]  = RBTree<T>::nil;
      this->link[RIGHT] = RBTree<T>::nil;

      if (NULL == o)
	{
	  this->color = BLACK;
	  this->link[LEFT] = NULL;
	  this->link[RIGHT] = NULL;
	}
    }
    ~RBTreeNode () {
      if (this->link[LEFT]->isNil () == false)
	delete this->link[LEFT];
      if (this->link[RIGHT]->isNil () == false)
	delete this->link[RIGHT];
    }
    inline bool isNil () { return (this->obj == NULL); }
    inline void swapColor (RBTreeNode &node) {
      Color c = this->color;
      this->color = node.color;
      node.color = c;
    }
    inline T * getObj () { return this->obj; }
    inline void setBlack () { this->color = BLACK; }
    inline void setRed () { this->color = RED; }
    inline Color getColor () { return this->color; }
    inline bool isBlack () { return (this->color == BLACK); }
    inline bool isRed () { return (this->color == RED); }    

    inline Side whichSide (RBTreeNode &node) {
      if (this->link[LEFT] == &node)
	return LEFT;
      else if (this->link[RIGHT] == &node)
	return RIGHT;
      else
	assert (0);
    }

    inline Side otherSide (Side s) {
      assert (s == LEFT || s == RIGHT);
      return (s == LEFT ? RIGHT : LEFT);
    }

    inline RBTreeNode * getBrother () {
      if (this->parent == NULL)
	return NULL;

      assert (this->parent->link[LEFT] == this || 
	      this->parent->link[RIGHT] == this);
      return (this->parent->link[LEFT] == this ? 
	      this->parent->link[RIGHT] : this->parent->link[LEFT]);
    }

    inline void attach (RBTreeNode &node) {
      assert (this->key != node.key);
      Side s = (node.key < this->key ? LEFT : RIGHT);
      this->attach (s, node);
    }

    inline void attach (Side s, RBTreeNode &node) {
      assert (s == LEFT || s == RIGHT);
      assert (this != &node);
      assert (this->link[s]->isNil ());
      this->link[s] = &node;
      if (! node.isNil ())
	node.parent = this;
    }

    inline RBTreeNode * detach (Side s) {
      assert (s == LEFT || s == RIGHT);

      if (this->isNil () || this->link[s]->isNil ())
	return RBTree<T>::nil;

      RBTreeNode * node = this->link[s];
      this->link[s]->parent = NULL;
      this->link[s] = RBTree<T>::nil;
      return node;
    }
    inline RBTreeNode * detach (RBTreeNode &node) {
      if (this->link[RIGHT] == &node)
	return this->detach (RIGHT);
      else if (this->link[LEFT] == &node)
	return this->detach (LEFT);
      else
	assert (0);

      return NULL;
    }
    inline RBTreeNode * searchMax () {
      if (! this->link[RIGHT]->isNil ())
	return this->link[RIGHT]->searchMax ();
      else 
	return this;
    }
    inline RBTreeNode * searchMin () {
      if (! this->link[LEFT]->isNil ())
	return this->link[LEFT]->searchMax ();
      else 
	return this;
    }
    void rotate (Side s) {
      RBTreeNode * nLeaf;   // New leaf
      RBTreeNode * nParent; // New parent
      RBTreeNode * nGrand;  // New grand father
      Side r = otherSide (s);

      nGrand = this->parent;
      nParent = this->detach (r);
      assert (nParent);

      nLeaf = nParent->detach (s);

      if (nGrand) {
	Side ps = nGrand->whichSide (*this);
	nGrand->detach (ps);
	nGrand->attach (ps, *nParent); 
      }
      else {
	this->tree->root = nParent;
      }

      nParent->attach (s, *this);

      if (! nLeaf->isNil ())
	this->attach (r, *nLeaf);
    }

    void adjustInsert ()
    {
      if (this->parent == NULL) {
	// this node is root
	this->setBlack ();
	return ;
      }
      else {
	if (this->parent->isRed ()) {
	  assert (this->parent->parent);
	  assert (this->parent->parent->isBlack ());
	  RBTreeNode * cParent = this->parent;
	  RBTreeNode * grand = this->parent->parent;
	  RBTreeNode * uncle = this->parent->getBrother ();
	  Side s;

	  if (uncle->isRed ()) {
	    uncle->setBlack ();
	    this->parent->setBlack ();
	    grand->setRed ();
	    grand->adjustInsert ();
	  }
	  else { 
	    if (this->parent->whichSide (*this) != 
		grand->whichSide (*this->parent)) {
	      s = otherSide (cParent->whichSide (*this));
	      cParent->rotate (s); 
	      cParent = this;
	    }
		  
	    s = otherSide (grand->whichSide (*cParent));
	    grand->rotate (s);

	    assert (grand->isBlack () && cParent->isRed ());
	    grand->swapColor (*cParent);
	  }
	}
      }
    }

    bool insert (RBTreeNode &node) 
    {
      if (this->key == node.key)
	{
	  // duplicated
	  return false;
	}
      else 
	{
	  Side s = (node.key < this->key ? LEFT : RIGHT);
	  if (! this->link[s]->isNil ())
	    return this->link[s]->insert (node);
	  else 
	    this->attach (s, node);
	}

      node.adjustInsert ();
      return true;
    }

    RBTreeNode * lookup (long long k)
    {
      if (this->key == k) {
	return this;
      }
      else {
	Side s = (k < this->key ? LEFT : RIGHT);
	return (this->link[s]->isNil () ? NULL : this->link[s]->lookup (k));
      }
    }

    void leave () {
      // only detach from tree, balancing color & tree in adjustLeave ()
      RBTreeNode * cParent = this->parent;

      if (this->link[LEFT]->isNil () && this->link[RIGHT]->isNil ()) {
	if (cParent) {
	  Side s = cParent->whichSide (*this);
	  cParent->detach (*this);

	  if (this->isBlack ()) {
	    cParent->link[s]->adjustLeave (cParent);
	  }
	}
	else  {
	  this->tree->root = NULL;	
	}
      }
      else if ((this->link[LEFT]->isNil()) ^ 
	       (this->link[RIGHT]->isNil ())) {
	Side s = (this->link[LEFT]->isNil () ? RIGHT : LEFT);
	RBTreeNode * cTarget = this->detach (s);

	if (cParent) {
	  cParent->detach (*this);
	  cParent->attach (*cTarget);
	}
	else 
	  this->tree->root = cTarget;

	if (this->isBlack ())
	  cTarget->adjustLeave (cParent);
      }
      else {
	// swap target node & maximum node in left subtree
	assert (! this->link[LEFT]->isNil () && 
		! this->link[RIGHT]->isNil ());

	RBTreeNode * cMax = this->link[LEFT]->searchMax ();
	RBTreeNode * mParent = cMax->parent;
	RBTreeNode * cLeft  = this->detach (LEFT);
	RBTreeNode * cRight = this->detach (RIGHT);
	RBTreeNode * mLeft  = cMax->detach (LEFT);

	this->attach (*mLeft);
	if (cParent) {
	  cParent->detach (*this);
	}
	else {
	  this->tree->root = NULL;
	}

	if (cMax != cLeft) {
	  // cMax have more 1 hop from THIS
	  mParent->detach (*cMax);
	  mParent->attach (*this);
	  cMax->attach (LEFT,  *cLeft);
	  cMax->attach (RIGHT, *cRight);
	}
	else {
	  // cMax == cLeft (cMax is left node of THIS)
	  assert (cMax->link[RIGHT]->isNil ());	 
	  cMax->attach (RIGHT, *cRight);
	  cMax->attach (LEFT,  *this);
	}

	if (cParent) {
	  cParent->attach (*cMax);
	}
	else {		
	  this->tree->root = cMax;
	}

	this->swapColor (*cMax);
	this->leave ();
      }   
    }

    void adjustLeave (RBTreeNode * cParent)
    {
      // nothing to do when node is root
      if (NULL == cParent) {
	this->setBlack ();
	return ;
      }
      if (this->isRed ()) {
	this->setBlack ();
	return ;
      }

      RBTreeNode * cNeighbor = 
	cParent->link[otherSide (cParent->whichSide (*this))];

      assert (cNeighbor) ;
      // cParent->tree->dumpTree ("Adjusting by Leave");

      if (cNeighbor->isRed ()) {
	Side s = cParent->whichSide (*this);
	assert (cParent->isBlack ());
	cParent->swapColor (*cNeighbor);
	cParent->rotate (s);
	cNeighbor = cParent->link[otherSide(s)];
      }
      else if (cParent->isBlack () && 
	       cNeighbor->link[LEFT]->isBlack () && 
	       cNeighbor->link[RIGHT]->isBlack ()) {
	assert (cNeighbor->isBlack ());
	cNeighbor->setRed ();
	return cParent->adjustLeave (cParent->parent);
      }      

      if (cParent->isRed () && 
	  cNeighbor->link[LEFT]->isBlack () && 
	  cNeighbor->link[RIGHT]->isBlack ()) {
	assert (cNeighbor->isBlack ());
	cParent->swapColor (*cNeighbor);
      }
      else {
	Side ns = cParent->whichSide(*cNeighbor); // Neighbor side
	Side os = otherSide (ns); // Other side

	if (cNeighbor->link[os]->isRed () &&
	    cNeighbor->link[ns]->isBlack ()) {	  
	  cNeighbor->swapColor (*cNeighbor->link[os]);
	  cNeighbor->rotate (ns);
	  cNeighbor = cParent->link[ns];
	}

	if (cNeighbor->link[ns]->isRed ()) {
	  cNeighbor->link[ns]->setBlack ();
	  cParent->swapColor (*cNeighbor);
	  cParent->rotate (os);
	}
      }      
    }

#ifdef DEBUG
    int checkBalance () {
      if (this->isNil ())
	return 1;

      if (this->isRed () &&
	  (this->link[LEFT]->isRed () || this->link[RIGHT]->isRed ()))
	{
	  debug (DEBUG, "Detected double RED, around key=%lld", this->key);
	  assert (0);
	}

      int lCount = this->link[LEFT]->checkBalance ();
      int rCount = this->link[RIGHT]->checkBalance ();
      if (lCount != rCount)
	{
	  debug (DEBUG, "Detected broken balance, around key=%lld", this->key);
	  assert (0);
	}
      
      return (this->isBlack () ? rCount + 1 : rCount);
    }

    void printNode (int depth) {
      char space[] = "     ";
      char header[0x1000] = "";
      if (this->link[RIGHT])
	this->link[RIGHT]->printNode (depth + 1);

      for (int i = 0; i < depth ; i++)
	strncat (header, space, sizeof (header) - 1);

      debug (DEBUG, "%s[%s:%lld %p]\n", header,
	     (this->color == RED ? "R" : "B"), this->key, this->obj);

      if (this->link[LEFT])
	this->link[LEFT]->printNode (depth + 1);
    }
#endif

  private:
    T * obj;
    long long key;
    Color color;
    RBTreeNode * parent, * link[2];
    RBTree * tree;
  } * root;

  static RBTreeNode * nil ;
  static bool DEBUG;

#ifdef DEBUG
  void dumpTree (std::string title) {
    debug (DEBUG, "======= %s ==============================================",
	   title.c_str ());

    if (this->root)
      this->root->printNode (0);
    else
      debug (true, " !! No tree");
  }
#endif

 public:
  RBTree () : root (NULL) {}
  ~RBTree () {
    delete this->root;
  }

  bool insert (long long key, T *p) {
    RBTreeNode * node = new RBTreeNode (key, p, this);

    assert (key >= 0);

#ifdef DEBUG
    this->dumpTree ("Before insertion");
#endif

    if (this->root) {
      if (! this->root->insert (*node)) {
	delete node;
	return false;
      }
    }
    else {
      this->root = node;
      node->setBlack ();
    }

#ifdef DEBUG
    this->dumpTree ("After insertion");
    this->root->checkBalance ();
#endif
    return true;
  }

  T * lookup (long long key)
  {
    if (NULL == this->root)
      return NULL; 

    RBTreeNode * node = this->root->lookup (key);
    return (node ? node->getObj () : NULL);
  }

  bool remove (long long key)
  {
    if (NULL == this->root)
      return false;

    RBTreeNode * node = this->root->lookup (key);
    if (NULL == node)
      return false;

#ifdef DEBUG
    this->dumpTree ("Before removing");
#endif
    node->leave ();
    delete node;

#ifdef DEBUG
    this->dumpTree ("After removing");
    this->root->checkBalance ();
#endif

    return true;
  }
};

template <typename T> class RBTree<T>::RBTreeNode * RBTree<T>::nil = new RBTreeNode (-1,0,0);
template <typename T> bool RBTree<T>::DEBUG = true;
