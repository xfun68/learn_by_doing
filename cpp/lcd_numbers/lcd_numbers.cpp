#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

typedef std::vector<std::string> lcd_number_t;

class LCDNumber {
  public:
    LCDNumber(const std::string& number, size_t size = 1) : size(size) {
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

      scale();
    }

    size_t lines_count() const {
      return lines.size();
    }

    std::string line(size_t i) const {
      return lines[i];
    }

  private:
    void scale() {
      scale_v();
      scale_h();
    }

    void scale_v() {
      std::vector<std::string> scaled_lines;

      for (size_t i = 0; i < lines.size(); ++i) {
        size_t repeats = ((i%2) == 1) ? size : 1;

        for (size_t count = 0; count < repeats; ++count) {
          scaled_lines.push_back(lines[i]);
        }
      }

      lines = scaled_lines;
    }

    void scale_h() {
      for (size_t i = 0; i < lines.size(); ++i) {
        std::string& line = lines[i];
        std::string scaled_line;

        for (size_t j = 0; j < line.size(); ++j) {
          size_t repeats = ((j%2) == 1) ? size : 1;

          for (size_t count = 0; count < repeats; ++count) {
            scaled_line += line[j];
          }
        }

        lines[i] = scaled_line;
      }
    }

  private:
    size_t size;
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
void parse_parameters(int argc, char**& argv, size_t& size, std::vector<std::string>& numbers);

int main(int argc, char* argv[]) {
  try {
    size_t size = 0;
    std::vector<std::string> numbers;

    parse_parameters(argc, argv, size, numbers);

    Display display;

    for (size_t i = 0; i < numbers.size(); ++i) {
      LCDNumber lcd_number(numbers[i], size);
      display.add(lcd_number);
    }

    display.print();
  } catch (std::string& error)
  {
    std::cout << error << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: Something wrong just happened!" << std::endl;
    std::cout << "\t" << e.what() << std::endl;
  }

  return 0;
}

void print(const LCDNumber& lcd_number) {
  for (size_t i = 0; i < lcd_number.lines_count(); ++i) {
    std::cout << lcd_number.line(i) << std::endl;
  }
}

void parse_parameters(int argc, char**& argv, size_t& size, std::vector<std::string>& numbers)
{
  const char* numbers_parameter = NULL;

  if (argc == 2) {
    size = 1;
    numbers_parameter = argv[1];
  } else if (argc == 4) {
    const char* argument = argv[1];
    if (std::string("-s") != argument) {
      throw(std::runtime_error(std::string("Unknown argument: ") + argument));
    }
    size = (size_t)atoi(argv[2]);
    numbers_parameter = argv[3];
  } else {
    throw(std::runtime_error("Wrong arguments!"));
  }

  std::string numbers_string(numbers_parameter);

  for (size_t i = 0; i < numbers_string.size(); ++i) {
    numbers.push_back(numbers_string.substr(i, 1));
  }
}

