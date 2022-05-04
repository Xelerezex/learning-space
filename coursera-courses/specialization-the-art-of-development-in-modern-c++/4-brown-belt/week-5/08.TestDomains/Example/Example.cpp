void TestSplitWithExcessEmpty()
{
    ASSERT_EQUAL(
            Split("ya.ru", "."),
            vector<string_view>({"ya", "ru"})
    );
}

void TestDomainReversedParts()
{
    const Domain domain("ya.ru");
    const auto reversed_parts_range = domain.GetReversedParts();
    const vector<string_view> reversed_parts(
            begin(reversed_parts_range), end(reversed_parts_range)
    );
    ASSERT_EQUAL(
            reversed_parts,
            vector<string_view>({"ru", "ya"})
    );
}

void TestIsSubdomainNonReflexive()
{
    ASSERT_EQUAL(
            IsSubdomain(Domain("ru"), Domain("ru")),
            true
    );
}

void TestIsSubdomainMixedArgs()
{
    ASSERT_EQUAL(
            IsSubdomain(Domain("m.ya.ru"), Domain("ya.ru")),
            true
    );
}

void TestDomainCheckerNoAbsorbation()
{
    const vector<Domain> domains =
    {
            Domain("ya.ru"),
            Domain("m.ya.ru")
    };
    ASSERT_EQUAL(
            DomainChecker(begin(domains), end(domains)).IsSubdomain(Domain("pets.ya.ru")),
            true
    );
}

void TestCheckDomainsInvertBool()
{
    ASSERT_EQUAL(
            CheckDomains(vector({Domain("ya.ru")}), vector({Domain("m.ya.ru")})),
            vector({false})
    );
}

void TestPrintCheckResultsGoodOrBad()
{
    ostringstream stream;
    PrintCheckResults(vector({true, false}), stream);
    ASSERT_EQUAL(stream.str(), "Good\nBad\n");
}

void TestReadDomainsExcessEmpty()
{
    stringstream stream;
    stream << 1 << '\n' << "ya.ru";
    ASSERT_EQUAL(
            ReadDomains(stream),
            vector({Domain("ya.ru")})
    );
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSplitWithExcessEmpty);
    RUN_TEST(tr, TestDomainReversedParts);
    RUN_TEST(tr, TestIsSubdomainNonReflexive);
    RUN_TEST(tr, TestIsSubdomainMixedArgs);
    RUN_TEST(tr, TestDomainCheckerNoAbsorbation);
    RUN_TEST(tr, TestCheckDomainsInvertBool);
    RUN_TEST(tr, TestPrintCheckResultsGoodOrBad);
    RUN_TEST(tr, TestReadDomainsExcessEmpty);

    return 0;
}
