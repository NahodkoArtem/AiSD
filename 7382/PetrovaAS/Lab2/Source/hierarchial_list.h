#include <iostream>
#include <list>
#include <cstdlib>

namespace h_list
{
    typedef char base;

    struct s_expr;
    struct  two_ptr {
        s_expr *hd;
        s_expr *tl;
    };	//end two_ptr;

    struct s_expr {
        bool tag; // true: atom, false: pair
        union
            {
            base atom;
            two_ptr pair;
        } node;		//end union node
    };			//end s_expr

    typedef s_expr *lisp;

    lisp head (const lisp s);
    lisp tail (const lisp s);
    lisp cons (const lisp h, const lisp t);
    lisp make_atom (const base x);
    bool isAtom (const lisp s);
    bool isNull (const lisp s);
    void destroy (lisp s);

    base getAtom (const lisp s);

    //________READING_LIST__________//
    void read_lisp ( lisp& y);
    void read_s_expr (base prev, lisp& y);
    void read_seq ( lisp& y);

    //________WRITING_LIST__________//
    void write_lisp (const lisp x, std::list<char> &mList);
    void write_seq (const lisp x, std::list<char> &mList);

} // end of namespace h_list
