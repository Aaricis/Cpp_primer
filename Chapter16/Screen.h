#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>
#include<vector>
using namespace std;

template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W> class Window_mgr;

template <unsigned H, unsigned W> 
const Screen<H, W>& operator<<(ostream &os, const Screen<H, W>&);

template <unsigned H, unsigned W> 
Screen<H, W>& operator>>(ostream &os, const Screen<H, W>&);

template <unsigned H, unsigned W>
class Screen{
    friend void Window_mgr<H, W>::clear(size_t i);
    friend const Screen<H, W> &operator<< <H,W>(ostream &os, const Screen<H, W>&);
public:
    Screen():contents(H*W, ' '){}
    Screen(char c):contents(H*W, c){}

    char get() const {return contents[cursor];}
    inline char get(unsigned l, unsigned r) const;

    inline Screen& move(unsigned l, unsigned r);
    inline Screen& set(char c);
    inline Screen& set(unsigned l, unsigned r, char c);
    inline Screen& set(const string &s);
    inline unsigned size() const;
private:
    unsigned cursor = 0;
    string contents;
    void do_display(ostream &os) const {os<<contents;}
};

template <unsigned H, unsigned W>
class Window_mgr{
public:
    Window_mgr();
    inline void clear(size_t i);
    inline void showScreen(ostream &os, size_t i);
    inline size_t addScreen(const Screen<H, W> &s);
private:
    vector<Screen<H, W>> screens;
};

template <unsigned H, unsigned W>
const Screen<H, W> &operator<<(ostream &os, const Screen<H, W>& sc){
    sc.do_display(os);
    return sc;
}

template <unsigned H, unsigned W>
Screen<H, W> & operator>>(istream &is, Screen<H, W> & sc)
{
	string s;
	is >> s;
	sc.set(s);
	return sc; 
}


template <unsigned H, unsigned W>
inline char Screen<H, W>::get(unsigned l, unsigned r) const{
    cursor = l*W+r;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(unsigned l, unsigned r){
    cursor = l*W+r;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(char c){
    contents[cursor] = c;
    return *this;
} 

template <unsigned H, unsigned W>
inline unsigned Screen<H, W>::size() const
{
	return W * H;
}


template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(unsigned l, unsigned r, char c){
    contents[l*W+r] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(const string &s){
    contents = s;
	contents.resize(H * W, ' ');
	return *this;
}

template <unsigned H, unsigned W>
Window_mgr<H, W>::Window_mgr():screens{Screen<H, W>(' ')} {}

template <unsigned H, unsigned W>
inline void Window_mgr<H, W>::clear(size_t i){
    screens[i].contents = string(H*W, ' ');
}

template <unsigned H, unsigned W>
inline void Window_mgr<H, W>::showScreen(ostream & os, size_t i)
{
	os << screens[i];
}

template <unsigned H, unsigned W>
inline size_t Window_mgr<H, W>::addScreen(const Screen<H, W> & s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

#endif