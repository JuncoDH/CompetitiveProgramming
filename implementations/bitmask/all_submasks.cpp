// Iterate over all submasks of a mask. CONSIDER SUBMASK = 0 APART.
for(int submask = mask; submask > 0; submask = (submask - 1) & mask) {}
