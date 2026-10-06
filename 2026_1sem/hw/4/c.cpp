#include <iostream>
struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};

struct Number : Expression
{
    Number(double value) : value(value) {
    }
    // ~Number() = default;

    double evaluate() const override{
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), right(right), op(op)
    { }
    // ~BinaryOperation() = default;
    ~BinaryOperation() override {
            delete left;
            delete right;
    }
    double evaluate() const override{
        switch(op){
            case '+':
                return left->evaluate()+right->evaluate();
                break;
            case '-':
                return left->evaluate()-right->evaluate();
                break;
            case '*':
                return left->evaluate()*right->evaluate();
                break;
            case '/':
                return left->evaluate()/right->evaluate();
                break;
            default:
                return 0;
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};


int main(){
    // Например, выражению 3 + 4.5 * 5 будет соответствовать следующий код:

    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return 0;
}

