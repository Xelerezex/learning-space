#pragma once

#include "headers.h"
#include "test_runner.h"

// TESTING ELEMENTS:
#include "date.h"
#include "database.h"
#include "condition_parser.h"

void TestClassDate();
void TestParseEvent();
void TestParseCondition();
void TestEmptyNode();
void TestDateComparisonNode();
void TestEventComparisonNode();
void TestClassDBAdd();
void TestClassDBPrint();
void TestClassDBDel();
void TestClassDBFind();
void TestClassDBLast();
void TestCustom();

void TestAll();
