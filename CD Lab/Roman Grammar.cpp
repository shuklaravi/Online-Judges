#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

class romanType {
   public:
      romanType();
      romanType(std::string);
      romanType(int);
      romanType(const romanType&);
     ~romanType() {}

      std::string getRoman() { return romanNum; }
      int         getDecimal() { return deciNum; }
      void        setRoman(std::string rNum) {
                     romanNum = rNum;
                     convToDeci();
      }
      void        setDeci(int dNum) {
                     deciNum = dNum;
                     convToRoman();
      }
   private:
      void        convToDeci();
      void        convToRoman();
      std::string romanNum;
      unsigned int deciNum;
};

romanType::romanType() {
    deciNum = 0;
    romanNum = "";
}

romanType::romanType(std::string rNum) : romanNum(rNum) {
    convToDeci();
}

romanType::romanType(int dNum) : deciNum(dNum) {
    convToRoman();
}

romanType::romanType(const romanType& copy) {
    romanNum = copy.romanNum;
    deciNum = copy.deciNum;
}

void romanType::convToDeci() {
     bool isRoman = true;

     deciNum = 0;
     for(int i = romanNum.size() - 1; i >= 0; i--) {
        switch(romanNum[i]) {
            case 'I':
            case 'i':
               if (deciNum < 5 || (deciNum >= 5 && romanNum[i+1] == 'I'))
                  deciNum += 1;
               else
                  deciNum -= 1;
               break;
            case 'V':
            case 'v':
               if (deciNum < 10 || (deciNum >= 10 && romanNum[i+1] == 'V'))
                  deciNum += 5;
               else
                  deciNum -= 5;
               break;
            case 'X':
            case 'x':
               if (deciNum < 50 || (deciNum >= 50 && romanNum[i+1] == 'X'))
                  deciNum += 10;
               else
                  deciNum -= 10;
               break;
            case 'L':
            case 'l':
               if (deciNum < 100 || (deciNum >= 100 && romanNum[i+1] == 'L'))
                  deciNum += 50;
               else
                  deciNum -= 50;
               break;
            case 'C':
            case 'c':
               if (deciNum < 500 || (deciNum >= 500 && romanNum[i+1] == 'C'))
                  deciNum += 100;
               else
                  deciNum -= 100;
               break;
            case 'D':
            case 'd':
               if (deciNum < 1000)
                  deciNum += 500;
               else
                  deciNum -= 500;
               break;
            case 'M':
            case 'm':
               deciNum += 1000;
               break;
            default:
               std::cout << "There is no such character \'" << romanNum[i]
                         << "\' in the Roman numeric system." << std::endl;
               isRoman = false;
               break;
        }
     }
     if(romanNum != romanType(deciNum).getRoman() && isRoman) {
        std::cout << "I believe " << romanNum << " should be written as ";
        convToRoman();
        std::cout << romanNum << "." << std::endl;
     }
}

void romanType::convToRoman() {
   int tempDeci = deciNum;
   std::string tempRoman;
   romanNum = "";

   while(tempDeci > 0) {
      if(tempDeci >= 1000) {
         tempDeci -= 1000;
         romanNum += 'M';
      }
      else if(tempDeci >= 900) {
         tempDeci -= 900;
         romanNum += "CM";
      }
      else if(tempDeci >= 500) {
         tempDeci -= 500;
         romanNum += 'D';
      }
      else if(tempDeci >= 400) {
         tempDeci -= 400;
         romanNum += "CD";
      }
      else if(tempDeci >= 100) {
         tempDeci -= 100;
         romanNum += 'C';
      }
      else if(tempDeci >= 90) {
         tempDeci -= 90;
         romanNum += "XC";
      }
      else if(tempDeci >= 50) {
         tempDeci -= 50;
         romanNum += 'L';
      }
      else if(tempDeci >= 40) {
         tempDeci -= 40;
         romanNum += "XL";
      }
      else if(tempDeci >= 10) {
         tempDeci -= 10;
         romanNum += 'X';
      }
      else if(tempDeci >= 9) {
         tempDeci -= 9;
         romanNum += "IX";
      }
      else if(tempDeci >= 5) {
         tempDeci -= 5;
         romanNum += 'V';
      }
      else if(tempDeci >= 4) {
         tempDeci -= 4;
         romanNum += "IV";
      }
      else {
         tempDeci -= 1;
         romanNum += 'I';
      }
   }
}


int main() {
    romanType r1;
    std::string val = "";
    int dVal = 0;
    bool isRoman;

    std::cout << "Roman/Decimal Converter\nI = 1\nV = 5\nX = 10\n"
              << "L = 50\nC = 100\nD = 500\nM = 1000\nQ to Quit\n" << std::endl;
    do {
       std::cout << "Enter a value to be converted: ";
       std::getline(std::cin,val,'\n');

       isRoman = true;
       for(int i = 0; i < val.size(); i++) {
          if (!isalpha(val[i])) {
             isRoman = false;
             break;
          }
          else val[i] = toupper(val[i]);
       }

       if(isRoman && toupper(val[0]) != 'Q') {
          r1.setRoman(val);
          std::cout << r1.getRoman() << " in decimal is " << r1.getDecimal() << "."
                    << std::endl;
       }
       else if(!isRoman) {
          std::istringstream conv;
          conv.str(val);
          conv >> dVal;
          if(dVal > 3999)
             std::cout << "Warning: The highest value you can get with the\n"
                       << "standard english alphabet is 3999.\nI believe ";
          r1.setDeci(dVal);
          std::cout << r1.getDecimal() << " in Roman numerals is " << r1.getRoman()
                    << "." << std::endl;
       }
       else
          std::cout << "Press any key to exit.";
       std::cin.get();
    } while(toupper(val[0]) != 'Q');
    return 0;
}
