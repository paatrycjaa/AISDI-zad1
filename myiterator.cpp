#include <iostream>
#include <iterator>
#include <vector>

class MyIterator {

    private:

        std::vector<int> vec;
        std::vector<int>::iterator current;

    public:

        MyIterator(std::vector<int> vec){
            this->vec = vec;
            current = findBegin();

        }

        std::vector<int>::iterator findBegin() {
            std::vector<int>::iterator begining = vec.begin();
            for(auto i = vec.begin(); i != vec.end() ; ++i){
                if (*i < *begining) begining = i;
            }
            return begining;
        }


        MyIterator& operator++(){
            auto i = current;
            for(++i; i != vec.end(); ++i){
                if (*i == *current){
                    current = i;
                    return *this;
                }
            }

            for(auto j = vec.begin(); j != vec.end() ; ++j){
                if(*j > *current){
                    current = j;
                    return *this;
                }
            }
            current = vec.end();
            return *this;
        }

        MyIterator myBegin(){
            current = findBegin();
            return *this;
        }

        MyIterator myEnd(){
            current = vec.end();
            return *this;
        }

        std::vector<int>::iterator myCurrent() const{
            return current;
        }

        bool operator!=(const MyIterator& it){
            return !(current == it.myCurrent());
        }

};

int main(){
    std::vector<int> container{2,6,7,10,4,5,7,3};
    MyIterator it(container);
    for(auto i = it.myBegin(); i != it.myEnd() ; ++i){
        std::cout << ( *(i.myCurrent()) ) << std::endl;
    }

    return 0;
}
