#pragma once
#include "date.h"

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And,
};

class Node {
    public:
        virtual bool Evaluate(const Date& date, const string& event) const = 0;

};

class DateComparisonNode : public Node {
    public:
        DateComparisonNode(const Comparison& comp, const Date& date);

    bool Evaluate(const Date& date, const string& event) const override;


    private:
        const Comparison CompType;
        const Date DateValue;
};


class EventComparisonNode : public Node {
    public:
        EventComparisonNode(const Comparison& comp, const string& val);

        bool Evaluate(const Date& date, const string& event) const override;

    private:
        const Comparison CompType;
        const string EventValue;
};


class LogicalOperationNode : public Node {
    public:
        LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> left, shared_ptr<Node> right);

        bool Evaluate(const Date& date, const string& event) const override;

    private:
        const LogicalOperation Operation;
        shared_ptr<const Node> Left;
        shared_ptr<const Node> Right;
};


class EmptyNode : public Node {
    public:
        EmptyNode();

        bool Evaluate(const Date& date, const string& event) const override;
};
