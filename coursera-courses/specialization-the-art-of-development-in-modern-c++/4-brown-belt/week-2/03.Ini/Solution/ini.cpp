#include "ini.h"

namespace Ini
{
    Section& Document::AddSection(std::string name)
    {
        return sections[name];
    }

    const Section& Document::GetSection(const std::string& name) const
    {
        return sections.at(name);
    }

    size_t Document::SectionCount() const
    {
        return sections.size();
    }

    Document Load(std::istream& input)
    {
        Document doc;
        Section * section_pointer = nullptr;
        std::string section_name;
        std::string current_line;


        while(getline(input, current_line))
        {
            if (current_line == "")
            {
                continue;
            }

            if (current_line[0] == '[')
            {
                // section_name    = std::string((current_line.begin() + 1), (current_line.end() - 1));
                section_name    = std::string(++current_line.begin(), --current_line.end());
                section_pointer = &doc.AddSection(section_name);
            }
            else
            {
                auto position = std::find(current_line.begin(), current_line.end(), '=');

                std::string key(current_line.begin(), position);
                std::string value(std::next(position), current_line.end());

                section_pointer->insert({key, value});
            }
        }

        return doc;
    }
}
