//Question 1
class Counter
{
    public:

    Counter(int _count, _limit){
        Counter = _count;
        limit = _limit;

        nCounter++;
    }

    void increment(){
        if(Counter < limit){
            nCounter++;
        }
    }

    void decrement(){
        if(Counter > 0){
            nCounter--;
        }
    }

    int getValue(){
        return Counter;
    }

    static int getNCounters(){
        return nCounter;
    }

    private:
        int Counter, limit;

        static int nCounter = 0;
}

//Question 2
class Counter2
{
    public:

    Counter2(int value){
        counter = value;

        nCounters++;

        counterID = nCounters;
    }

    void increment(){
        counter++;
    }

    void decrement(){
        counter--;
    }

    int getCounterID(){
        return counterID;
    }

    private:
        int counter, counterID;

        static int nCounters = 0;
}

//Question 3
class Window
{
public:

    Window(_width, _height){
        width = _width;
        height = _height;
    }

    friend bool areSameSize(Window obj, Window obj2){
        if(obj.height == obj2.height and obj.width == obj2.width){
            return true;
        }

        return false

    }

    int width, height;
}

//Question 4
class SavingsAccount : public BankAccount
{
    public:

    SavingsAccount(std::string interest_type, int interest_rate){
        interestRate = interest_rate;

        if(interest_type == "compound"){
            interestType = 2;
        }
        else{
            interestType = 1;
        }
    }

    int getInterestType(){return interestType;}
    double getInterestRate(){return interestRate;}

    int interestType;
    double interestRate;
}

//Question 5
class WindowWithBorder : public Window
{
    WindowWithBorder(int width){
        BorderWidth = width;
    }

    int getUseableWidth(){
        return getWidth() - BorderWidth;
    }
    public:
    int BorderWidth;
}
