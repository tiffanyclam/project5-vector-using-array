#include "main.h"

int main(){
    try {
        // INT TESTING
        Vector<int> v1;
        v1.printInternal();
        cout << "-----------V1------------" << endl;

        Vector<int> v2(20);
        v2.printInternal();
        cout << "-----------V2------------" << endl;
        
        Vector<int> v3(3,5);
        v3.printInternal();
        cout << "-----------V3------------" << endl;
        
        v3.push_back(5);
        v3.push_back(10);
        v3.push_back(15);
        v3.printInternal();
        cout << "-------end pushbacks-----" << endl;

        v3.insert(1, 8);
        v3.printInternal();
        cout << "-------end of insert-----" << endl;
        
        v3.assign(0, 3);
        v3.printInternal();
        cout << "-------end of assign-----" << endl;

        cout << "Empty? " << v3.empty() << endl;
        cout << "Size: " << v3.size() << endl;
        cout << "Capacity: " << v3.capacity() << endl;
        cout << "At position 3: " << v3.at(3) << endl;
        cout << "At v3[4]: " << v3[4] << endl;
        cout << "-------end of detail-----" << endl;

        Vector<int> v4(v3);
        v4.printInternal();
        cout << "-----------V4------------" << endl;

        v4.remove(2);
        v4.remove(3);
        v4.printInternal();
        cout << "-------end of remove-----" << endl;
        
        v4.insert(3, 30);
        v4.insert(0, 1);
        v4.insert(1, 2);
        v4.insert(3, 9);
        v4.printInternal();
        cout << "-------end of insert-----" << endl;
        
        v4.push_back(35);
        v4.push_back(40);
        v4.push_back(45);
        v4.push_back(-1);
        v4.printInternal();
        cout << "------end of pushback----" << endl;
        
        v3.printInternal();
        cout << "------end of print v3----" << endl;

        v4.printInternal();
        cout << "------end of print v4----" << endl;

        v3.sort();
        v3.printInternal();
        cout << "------end of sort v3-----" << endl;

        v4.sort();
        v4.printInternal();
        cout << "------end of sort v4-----" << endl;

        v3 = v4;
        v3.printInternal();
        cout << "------end of v3 = v4-----" << endl;
        
        v4.clear();
        v4.printInternal();
        cout << "------end of clear v4----" << endl;

        v3.resize(26, 2);
        v3.printInternal();
        cout << "------end of resize v3---" << endl;
        
        v3.resize(12);
        v3.printInternal();
        cout << "------end of resize v3---" << endl;
        
        // STRING TESTING
        Vector<string> s1;
        s1.printInternal();
        cout << "-----------S1------------" << endl;

        Vector<string> s2(20);
        s2.printInternal();
        cout << "-----------S2------------" << endl;

        Vector<string> s3(5, "hi");
        s3.printInternal();
        cout << "-----------S3------------" << endl;

        Vector<string>s4(s3);
        s4.printInternal();
        cout << "------------S4-----------" << endl;

        s3.assign(0, "abc");
        s3.push_back("xyz");
        s3.insert(2, "def");
        s3.printInternal();
        cout << "----------addingS3-------" << endl;

        s3.remove(4);
        s3.sort();
        s3.printInternal();
        cout << "---------rem/sortS3------" << endl;

        s3.push_back("qrs");
        s3.push_back("hij");
        s3.push_back("klm");
        s3.push_back("tuv");
        s3.push_back("nop");
        s3.printInternal();
        cout << "---------pushbackS3------" << endl;

        s3.resize(18, "wxi");
        s3.printInternal();
        cout << "---------resizingS3------" << endl;

        s4.clear();
        s4.printInternal();
        cout << "-------clearS4-----------" << endl;

        s4 = s3;
        s4.printInternal();
        cout << "--------copyS4-----------" << endl;

        cout << "Empty? " << s4.empty() << endl;
        cout << "Size: " << s4.size() << endl;
        cout << "Capacity: " << s4.capacity() << endl;
        cout << "At position 3: " << s4.at(3) << endl;
        cout << "At s4[3]: " << s4[3] << endl;
        cout << "-------end of detail-----" << endl;
        
//        Vector<string> s5(s4);
//        s5.push_back("pgl");
//        s5.assign(3, "mov");
//        s5.printInternal();
//        s5 = s4;
//        s5.printInternal();
    }
    
    catch (out_of_range &e){
        cout << "Out of range: "
        << e.what() << endl;
    }
    catch (invalid_argument &e){
        cout << "Invalid argument: "
        << e.what() << endl;
    }
    catch (logic_error &e){
        cout << "Logic error: "
        << e.what() << endl;
    }
    catch (...){
        cout << "Uncaught exception" << endl;
    }
    
    return 0;
}
