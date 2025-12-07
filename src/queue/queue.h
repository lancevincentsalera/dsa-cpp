// define the abstract Queue class
// and its virtual functions
class Queue {
    public:
        virtual ~Queue() = default;
        virtual void enqueue(int num) = 0;
        virtual int dequeue() = 0;
        virtual int first() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
};