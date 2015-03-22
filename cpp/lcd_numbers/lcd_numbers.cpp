#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> lcd_number_t;

class LCDNumber {
  public:
    LCDNumber(const std::string& number) {
      if (number == "0") {
        lines.push_back(" - "); lines.push_back("| |"); lines.push_back("   "); lines.push_back("| |"); lines.push_back(" - ");
      } else if (number == "1") {
        lines.push_back("   "); lines.push_back("  |"); lines.push_back("   "); lines.push_back("  |"); lines.push_back("   ");
      } else if (number == "2") {
        lines.push_back(" - "); lines.push_back("  |"); lines.push_back(" - "); lines.push_back("|  "); lines.push_back(" - ");
      } else if (number == "3") {
        lines.push_back(" - "); lines.push_back("  |"); lines.push_back(" - "); lines.push_back("  |"); lines.push_back(" - ");
      } else if (number == "4") {
        lines.push_back("   "); lines.push_back("| |"); lines.push_back(" - "); lines.push_back("  |"); lines.push_back("   ");
      } else if (number == "5") {
        lines.push_back(" - "); lines.push_back("|  "); lines.push_back(" - "); lines.push_back("  |"); lines.push_back(" - ");
      } else if (number == "6") {
        lines.push_back(" - "); lines.push_back("|  "); lines.push_back(" - "); lines.push_back("| |"); lines.push_back(" - ");
      } else if (number == "7") {
        lines.push_back(" - "); lines.push_back("  |"); lines.push_back("   "); lines.push_back("  |"); lines.push_back("   ");
      } else if (number == "8") {
        lines.push_back(" - "); lines.push_back("| |"); lines.push_back(" - "); lines.push_back("| |"); lines.push_back(" - ");
      } else if (number == "9") {
        lines.push_back(" - "); lines.push_back("| |"); lines.push_back(" - "); lines.push_back("  |"); lines.push_back(" - ");
      } else {
        lines.push_back(" - "); lines.push_back("|  "); lines.push_back(" - "); lines.push_back("|  "); lines.push_back(" - ");
      }
    }

    size_t lines_count() const {
      return lines.size();
    }

    std::string line(size_t i) const {
      return lines[i];
    }

  private:
    std::vector<std::string> lines;
};

class Display {
  public:
    void add(LCDNumber& lcd_number) {
      lcd_numbers.push_back(lcd_number);
    }

    void print(){
      size_t max_lines_count = 0;

      for (size_t i = 0; i < lcd_numbers.size(); ++i) {
        max_lines_count = std::max(max_lines_count, lcd_numbers[i].lines_count());
      }

      for (size_t ln = 0; ln < max_lines_count; ++ln) {
        std::string line;

        for (size_t i = 0; i < lcd_numbers.size(); ++i) {
          LCDNumber& lcd_number = lcd_numbers[i];
          line += lcd_numbers[i].line(ln);
          line += " ";
        }

        std::cout << line << std::endl;
      }
    }

  private:
    std::vector<LCDNumber> lcd_numbers;
};

void print(const LCDNumber& lcd_number);
void parse_parameters(int argc, char**& argv);

int main(int argc, char* argv[]) {
  try {
    parse_parameters(argc, argv);

    std::string numbers(argv[1]);

    Display display;

    for (size_t i = 0; i < numbers.size(); ++i) {
      LCDNumber lcd_number(numbers.substr(i, 1));
      display.add(lcd_number);
    }

    display.print();
  } catch (std::string& error)
  {
    std::cout << error << std::endl;
  } catch (...) {
    std::cout << "Error: Something wrong just happened!" << std::endl;
  }

  return 0;
}

void print(const LCDNumber& lcd_number) {
  for (size_t i = 0; i < lcd_number.lines_count(); ++i) {
    std::cout << lcd_number.line(i) << std::endl;
  }
}

void parse_parameters(int argc, char**& argv)
{
  if (argc != 2) {
    std::cout << "Error: bad parameters!" << std::endl;
    throw("Wrong arguments!");
  }
}

