// Interpreter.cpp
// Real-world example: Simple expression interpreter for binary add operations

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

struct Expr { virtual ~Expr()=default; virtual int eval() const=0; };
struct Number : Expr { int v; Number(int x):v(x){} int eval() const override { return v; } };
struct Add : Expr { std::unique_ptr<Expr> l, r; Add(std::unique_ptr<Expr> a, std::unique_ptr<Expr> b):l(std::move(a)),r(std::move(b)){} int eval() const override { return l->eval()+r->eval(); } };

// Very small parser: "num+num"
std::unique_ptr<Expr> parse(const std::string& s){
    std::istringstream in(s);
    int a, b; char op; in>>a>>op>>b; return std::make_unique<Add>(std::make_unique<Number>(a), std::make_unique<Number>(b));
}

int main(){
    auto expr = parse("3+4");
    std::cout<<"3+4 = "<<expr->eval()<<"\n";
    return 0;
}
