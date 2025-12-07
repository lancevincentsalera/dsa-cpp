// define the abstract Stack class
// and its virtual functions
class Stack {
    public:
        virtual ~Stack() = default;
        virtual void push(int value) = 0;
        virtual int pop() = 0;
        virtual int top() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
};