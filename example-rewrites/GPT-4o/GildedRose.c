#include <string.h>
#include "GildedRose.h"
#include <stdio.h>

Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

extern char* 
print_item(char* buffer, Item* item) 
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

void update_aged_brie(Item *item) {
    if (item->quality < 50) {
        item->quality += 1;
    }
    item->sellIn -= 1;
    if (item->sellIn < 0 && item->quality < 50) {
        item->quality += 1;
    }
}

void update_backstage_passes(Item *item) {
    if (item->quality < 50) {
        item->quality += 1;
        if (item->sellIn < 11 && item->quality < 50) {
            item->quality += 1;
        }
        if (item->sellIn < 6 && item->quality < 50) {
            item->quality += 1;
        }
    }
    item->sellIn -= 1;
    if (item->sellIn < 0) {
        item->quality = 0;
    }
}

void update_sulfuras(Item *item) {
    // Sulfuras doesn't need any updates
}

void update_common_item(Item *item) {
    if (item->quality > 0) {
        item->quality -= 1;
    }
    item->sellIn -= 1;
    if (item->sellIn < 0 && item->quality > 0) {
        item->quality -= 1;
    }
}

void update_item(Item *item) {
    if (strcmp(item->name, "Aged Brie") == 0) {
        update_aged_brie(item);
    } else if (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0) {
        update_backstage_passes(item);
    } else if (strcmp(item->name, "Sulfuras, Hand of Ragnaros") == 0) {
        update_sulfuras(item);
    } else {
        update_common_item(item);
    }
}

void update_quality(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        update_item(&items[i]);
    }
}