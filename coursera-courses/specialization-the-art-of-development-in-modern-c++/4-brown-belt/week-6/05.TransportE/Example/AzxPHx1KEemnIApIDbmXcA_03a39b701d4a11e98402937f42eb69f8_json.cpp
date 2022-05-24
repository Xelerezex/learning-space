#include "json.h"

using namespace std;

namespace Json {

  Node LoadArray(istream& input) {
    vector<Node> result;

    for (char c; input >> c && c != ']'; ) {
      if (c != ',') {
        input.putback(c);
      }
      result.push_back(LoadNode(input));
    }

    return Node(move(result));
  }

  Node LoadBool(istream& input) {
    string s;
    while (isalpha(input.peek())) {
      s.push_back(input.get());
    }
    return Node(s == "true");
  }

  Node LoadNumber(istream& input) {
    bool is_negative = false;
    if (input.peek() == '-') {
      is_negative = true;
      input.get();
    }
    int int_part = 0;
    while (isdigit(input.peek())) {
      int_part *= 10;
      int_part += input.get() - '0';
    }
    if (input.peek() != '.') {
      return Node(int_part * (is_negative ? -1 : 1));
    }
    input.get();  // '.'
    double result = int_part;
    double frac_mult = 0.1;
    while (isdigit(input.peek())) {
      result += frac_mult * (input.get() - '0');
      frac_mult /= 10;
    }
    return Node(result * (is_negative ? -1 : 1));
  }

  Node LoadString(istream& input) {
    string line;
    getline(input, line, '"');
    return Node(move(line));
  }

  Node LoadDict(istream& input) {
    Dict result;

    for (char c; input >> c && c != '}'; ) {
      if (c == ',') {
        input >> c;
      }

      string key = LoadString(input).AsString();
      input >> c;
      result.emplace(move(key), LoadNode(input));
    }

    return Node(move(result));
  }

  Node LoadNode(istream& input) {
    char c;
    input >> c;

    if (c == '[') {
      return LoadArray(input);
    } else if (c == '{') {
      return LoadDict(input);
    } else if (c == '"') {
      return LoadString(input);
    } else if (c == 't' || c == 'f') {
      input.putback(c);
      return LoadBool(input);
    } else {
      input.putback(c);
      return LoadNumber(input);
    }
  }

  Document Load(istream& input) {
    return Document{LoadNode(input)};
  }

  template <>
  void PrintValue<string>(const string& value, ostream& output) {
    output << '"' << value << '"';
  }

  template <>
  void PrintValue<bool>(const bool& value, std::ostream& output) {
    output << std::boolalpha << value;
  }

  template <>
  void PrintValue<std::vector<Node>>(const std::vector<Node>& nodes, std::ostream& output) {
    output << '[';
    bool first = true;
    for (const Node& node : nodes) {
      if (!first) {
        output << ", ";
      }
      first = false;
      PrintNode(node, output);
    }
    output << ']';
  }

  template <>
  void PrintValue<Dict>(const Dict& dict, std::ostream& output) {
    output << '{';
    bool first = true;
    for (const auto& [key, node]: dict) {
      if (!first) {
        output << ", ";
      }
      first = false;
      PrintValue(key, output);
      output << ": ";
      PrintNode(node, output);
    }
    output << '}';
  }

  void PrintNode(const Json::Node& node, ostream& output) {
    visit([&output](const auto& value) { PrintValue(value, output); },
          node.GetBase());
  }

  void Print(const Document& document, ostream& output) {
    PrintNode(document.GetRoot(), output);
  }

}
