#include "node.h"

// DateComparisonNode Class Methods:

DateComparisonNode::DateComparisonNode(const Comparison& comp, const Date& date) : CompType(comp), DateValue(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    bool condition;

    switch (CompType) {
        case Comparison::Less:
            condition = (date < DateValue);
            break;
        case Comparison::LessOrEqual:
            condition = (date <= DateValue);
            break;
        case Comparison::Greater:
            condition = (date > DateValue);
            break;
        case Comparison::GreaterOrEqual:
            condition = (date >= DateValue);
            break;
        case Comparison::Equal:
            condition = (date == DateValue);
            break;
        case Comparison::NotEqual:
            condition = (date != DateValue);
            break;
        default:
            return 0;
            break;
            //throw logic_error("Unknown comparison token (DateComparisonNode::Evaluate()).");
    };

    return condition;
}


// EventComparisonNode Class Methods:

EventComparisonNode::EventComparisonNode(const Comparison& comp, const string& val) : CompType(comp), EventValue(val) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    bool condition;

    switch (CompType) {
        case Comparison::Less:
            condition = (event < EventValue);
            break;
        case Comparison::LessOrEqual:
            condition = (event <= EventValue);
            break;
        case Comparison::Greater:
            condition = (event > EventValue);
            break;
        case Comparison::GreaterOrEqual:
            condition = (event >= EventValue);
            break;
        case Comparison::Equal:
            condition = (event == EventValue);
            break;
        case Comparison::NotEqual:
            condition = (event != EventValue);
            break;
        default:
            return 0;
            break;
            //throw logic_error("Unknown comparison token (DateComparisonNode::Evaluate()).");
    };

    return condition;
}


// LogicalOperationNode Class Methods:

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> left, shared_ptr<Node> right) : Operation(op), Left(left), Right(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    bool condition;

    switch (Operation) {
        case LogicalOperation::Or:
            condition = Left->Evaluate(date, event) || Right->Evaluate(date, event);
            break;
        case LogicalOperation::And:
            condition = Left->Evaluate(date, event) && Right->Evaluate(date, event);
            break;
    };

    return condition;
}


// EmptyNode Class Methods:
EmptyNode::EmptyNode() {}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return /*NULL*/ true;
}
