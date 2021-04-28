#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const* number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const* operation) = 0;
    virtual ~Visitor() { }
};

struct Expression {
    virtual double evaluate() const = 0;
    virtual void visit(Visitor* vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression {
    Number(double value) : value(value) {}
    double evaluate() const {
        return value;
    }

    double get_value() const { return value; }

    void visit(Visitor* visitor) const { visitor->visitNumber(this); }

    ~Number() {}
private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() const {
        if (op == '+') return left->evaluate() + right->evaluate();
        if (op == '-') return left->evaluate() - right->evaluate();
        if (op == '*') return left->evaluate() * right->evaluate();
        if (op == '/') return left->evaluate() / right->evaluate();
    }

    Expression const* get_left() const { return left; }
    Expression const* get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor* visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const* left;
    Expression const* right;
    char op;
};


// Этот класс вам нужно реализовать 
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value() << " ";
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "( ";
        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ") ";
    }
};


int main()
{
    std::cout << "Hello World" << std::endl;
    Expression * numb = new Number(3.5);
    Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));
    Expression * dube = new BinaryOperation(new Number(8.5), '+', new Number(3.2));
    Expression * kube = new BinaryOperation(sube, '*', dube);
    //Expression* a1 = new Number(5.2);
    //std::cout << b.evaluate() << std::endl;
    //PrintVisitor  PV;
    
    
    PrintVisitor visitor;
    numb->visit(&visitor);
    sube->visit(&visitor);
    std::cout << std::endl;
    dube->visit(&visitor);
    std::cout << std::endl;
    kube->visit(&visitor);
    return 0;
}
