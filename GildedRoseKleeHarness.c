#include "GildedRose.h"
#include <assert.h>
#include <stdbool.h>


int main() {
    int nameChoice;
    char *name;
    int sellIn;
    int quality;
	klee_make_symbolic(&sellIn, sizeof(sellIn), "sellIn");
    klee_make_symbolic(&quality, sizeof(quality), "quality");
    klee_make_symbolic(&nameChoice, sizeof(nameChoice), "nameChoice");
    
    // Optionally, reduce the search space to valid states.
    // This makes verification more efficient allows more flexibility of implementation.

    // klee_assume(quality >= 0);
    // klee_assume(quality <= 50);
    // klee_assume(sellIn >= 0);

    klee_assume(nameChoice >= 0 && nameChoice <= 2);
    switch (nameChoice) {
        case 0: name = "Aged Brie";
        break;
        case 1: name = "Backstage passes to a TAFKAL80ETC concert";
        break;
        case 2: name = "Sulfuras, Hand of Ragnaros";
        break;
        case 3: name = "..some normal item..";
        break;
    }
    Item itemRef = { .quality = quality, .sellIn = sellIn, .name = name };
    Item item = { .quality = quality, .sellIn = sellIn, .name = name };

    update_quality(&item, 1);
    update_quality_reference(&itemRef, 1);
  	assert(item.quality == itemRef.quality);
    assert(item.sellIn == itemRef.sellIn);
	return 0;
}
