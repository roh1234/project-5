/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;

size_t PageTable::get_present_page_count() const
{
    int j = 0;
    for (int i = 0; i < this->rows.size(); i++)
    {
        if (this->rows[i].present == true)
        {
            j++;
        }
    }
    return j;
}

size_t PageTable::get_oldest_page() const
{
     for (int i = 0; i < this->rows.size(); i++)
    {
        if (this->rows[i].present == true)
        {
            return i;
        }
    }
    return 0;
}

size_t PageTable::get_least_recently_used_page() const
{
    size_t lru = 0;
    for (int i = 0; i < this->rows.size(); i++)
    {
        if (this->rows[i].present == true)
        {
            lru = i;
        }
    }
    return lru;
}
