//
// Created by Ciprian Marin on 26.10.2022.
//

#include "PIF.h"
#include <ostream>

ostream &operator<<(ostream &os, const PIF &pif) {
    for_each(pif.table.begin(), pif.table.end(), [&os](pair<string, int> el) {
        os<<el.first<<" "<<el.second<<"\n";
    });
    return os;
}
