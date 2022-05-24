#include "json.h"

#include <iomanip>
#include <variant>

using namespace std;

namespace Json {

  Document::Document(Node root) : root(move(root)) {
  }

  const Node& Document::GetRoot() const {
    return root;
  }

  Node LoadNode(istream& input);

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

  Node LoadInt(istream& input) {
    int result = 0;
    while (isdigit(input.peek())) {
      result *= 10;
      result += input.get() - '0';
    }
    return Node(result);
  }

  Node LoadUnsignedDecimal(istream& input) {
    int result = 0;

    int sign = 1;
    if (input.peek() == '-') {
      input.ignore();
      sign = -1;
    }

    while (isdigit(input.peek())) {
      result *= 10;
      result += input.get() - '0';
    }

    if (input.peek() != '.') {
      return Node(sign * result);
    }

    input.ignore();
    double double_res = result;
    double factor = 0.1;
    while (isdigit(input.peek())) {
      int digit = input.get() - '0';
      double_res += digit * factor;
      factor *= 0.1;
    }
    return Node(sign * double_res);
  }

  Node LoadString(istream& input) {
    string line;
    getline(input, line, '"');
    return Node(move(line));
  }

  Node LoadBool(istream& input) {
    string value(5, '\0');

    for (int i = 0; i < 4; ++i) {
      input >> value[i];
    }

    if (value.substr(0, 4) == "true") {
      return Node(true);
    }

    input >> value[4];
    return Node(false);
  }

  Node LoadDict(istream& input) {
    map<string, Node> result;

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
      return LoadUnsignedDecimal(input);
    }
  }

  Document Load(istream& input) {
    return Document{LoadNode(input)};
  }

  void PrintNode(const Node& node, std::ostream& output) {
    if (holds_alternative<vector<Node>>(node)) {
      output << "[";
      bool first_elem = true;
      for (const auto& elem : node.AsArray()) {
        if (first_elem) {
          first_elem = false;
        }
        else {
          output << ", ";
        }
        PrintNode(elem, output);
      }
      output << "]";
    }
    else if (holds_alternative<std::map<std::string, Node>>(node)) {
      output << "{";
      bool first_elem = true;
      for (const auto& [key, value] : node.AsMap()) {
        if (first_elem) {
          first_elem = false;
        }
        else {
          output << ", ";
        }
        output << "\"" << key << "\"" << ": ";
        PrintNode(value, output);
      }
      output << "}";
    }
    else if (holds_alternative<int>(node)) {
      output << node.AsInt();
    }
    else if (holds_alternative<double>(node)) {
      output << fixed << setprecision(6) << node.AsDouble();
    }
    else if (holds_alternative<bool>(node)) {
      output << boolalpha << node.AsBool();
    }
    else if (holds_alternative<string>(node)) {
      output << "\"" << node.AsString() << "\"";
    }
  }

  void Print(const Document& doc, std::ostream& output) {
    PrintNode(doc.GetRoot(), output);
  }

}
