#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>


#include "test_runner.h"


bool IsSubdomain(std::string_view subdomain, std::string_view domain)
{
    auto i = subdomain.size() - 1;
    auto j = domain.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (subdomain[i--] != domain[j--])
        {
            return false;
        }
    }
    return (i < 0 && domain[j] == '.')
            || (j < 0 && subdomain[i] == '.');
}


std::vector<std::string> ReadDomains()
{
    size_t count;
    std::cin >> count;

    std::vector<std::string> domains;
    for (size_t i = 0; i < count; ++i)
    {
        std::string domain;
        getline(std::cin, domain);
        domains.push_back(domain);
    }
    return domains;
}


int main()
{
    const std::vector<std::string> banned_domains = ReadDomains();
    const std::vector<std::string> domains_to_check = ReadDomains();

    for (std::string_view domain : banned_domains)
    {
        std::reverse(begin(domain), end(domain));
    }

    std::sort(begin(banned_domains), end(banned_domains));

    size_t insert_pos = 0;
    for (const std::string& domain : banned_domains)
    {
        if (insert_pos == 0 || !IsSubdomain(domain, banned_domains[insert_pos - 1]))
        {
            std::string swapable = domain;
            std::swap(banned_domains[insert_pos++], swapable);
        }
    }

    banned_domains.resize(insert_pos);

    for (const std::string_view domain : domains_to_check)
    {
        if (const auto it = std::upper_bound(begin(banned_domains), end(banned_domains), domain);
                it != begin(banned_domains) && IsSubdomain(domain, *prev(it)))
        {
            cout << "Good" << std::endl;
        }
        else
        {
            cout << "Bad" << std::endl;
        }
    }

    return 0;
}
