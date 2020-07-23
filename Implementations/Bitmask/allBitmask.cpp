//iterate over all subsets of a set
//0, lsb, 2lsb, 2lsb & lsb, 3lsb...
//do{
//    } while((b = (b - x) & x));

//m will be all submask of m, consider 0 appart
for(m = n; m > 0; m = (m-1)&n) {}
for(submask = mask; submask > 0; submask = (submask-1)&mask) {}
