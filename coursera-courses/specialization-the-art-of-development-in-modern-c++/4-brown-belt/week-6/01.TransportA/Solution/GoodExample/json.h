#pragma once

#include <istream>
#include <map>
#include <string>
#include <variant>
#include <vector>

namespace Json {

  class Node : public std::variant<std::vector<Node>,
                                   std::map<std::string, Node>,
                                   int,
                                   double,
                                   bool,
                                   std::string> {
  public:
    using variant::variant;

    const auto& AsArray() const {
      return std::get<std::vector<Node>>(*this);
    }
    const auto& AsMap() const {
      return std::get<std::map<std::string, Node>>(*this);
    }
    int AsInt() const {
      return std::get<int>(*this);
    }
    double AsDouble() const {
      return std::get<double>(*this);
    }
    bool AsBool() const {
      return std::get<bool>(*this);
    }
    const auto& AsString() const {
      return std::get<std::string>(*this);
    }
  };

  class Document {
  public:
    explicit Document(Node root);

    const Node& GetRoot() const;

  private:
    Node root;
  };

  Document Load(std::istream& input);
  void Print(const Document& doc, std::ostream& output);

}
