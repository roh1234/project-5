/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"

using namespace std;


Process* Process::read_from_input(std::istream& in) {
    size_t num_bytes = 0;

    Page* page;
    vector<Page*> pages;

    while ((page = Page::read_from_input(in)) != nullptr) {
        pages.push_back(page);
        num_bytes += page->size();
    }

    return new Process(num_bytes, pages);
}


size_t Process::size() const
{
    // TODO
    return this->num_bytes;
}


bool Process::is_valid_page(size_t index) const
{
    if(index < pages.size()){
        return true;
    }
    return false;
}


size_t Process::get_rss() const
{
    int j = 0;
    for (size_t i = 0; i < page_table.rows.size(); i++) {
    if (page_table.rows[i].present == true){
        j++;
    }
  }
        return j;
}


double Process::get_fault_percent() const
{
    if (memory_accesses > 0){
    return double (double(this->page_faults)/double(memory_accesses)*100);
    }
    return 0;
}
