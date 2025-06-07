class Solution {
    public int numTrees(int n) {
        long[] catalanNumbers = {
    1L,          // C1
    2L,          // C2
    5L,          // C3
    14L,         // C4
    42L,         // C5
    132L,        // C6
    429L,        // C7
    1430L,       // C8
    4862L,       // C9
    16796L,      // C10
    58786L,      // C11
    208012L,     // C12
    742900L,     // C13
    2674440L,    // C14
    9694845L,    // C15
    35357670L,   // C16
    129644790L,  // C17
    477638700L,  // C18
    1767263190L, // C19
    6564120420L  // C20
};
   return (int)(catalanNumbers[n-1]);
    }
}