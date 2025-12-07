// define the abstract Deque class
// and its virtual functions
class Deque {
    public:
        virtual ~Deque() = default;
        virtual void addFirst(int num) = 0;
        virtual void addLast(int num) = 0;
        virtual int removeFirst() = 0;
        virtual int removeLast() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
};