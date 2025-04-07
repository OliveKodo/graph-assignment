// tomergal40@gmail.com
#include "union_find.hpp"
#include <iostream>

int main() {
    try {
        // Create a UnionFind data structure with 10 elements
        std::cout << "Creating a UnionFind with 10 elements..." << std::endl;
        graph::UnionFind uf(10);
        
        // Initially all elements should be in separate sets
        std::cout << "\nChecking initial state:" << std::endl;
        std::cout << "Elements 0 and 1 in same set: " << (uf.sameSet(0, 1) ? "Yes" : "No") << std::endl;
        std::cout << "Elements 5 and 7 in same set: " << (uf.sameSet(5, 7) ? "Yes" : "No") << std::endl;
        
        // Perform some unions
        std::cout << "\nPerforming unions:" << std::endl;
        
        std::cout << "Union sets containing 0 and 1" << std::endl;
        uf.unionSets(0, 1);
        
        std::cout << "Union sets containing 2 and 3" << std::endl;
        uf.unionSets(2, 3);
        
        std::cout << "Union sets containing 4 and 5" << std::endl;
        uf.unionSets(4, 5);
        
        std::cout << "Union sets containing 6 and 7" << std::endl;
        uf.unionSets(6, 7);
        
        std::cout << "Union sets containing 8 and 9" << std::endl;
        uf.unionSets(8, 9);
        
        // Check some set relationships after unions
        std::cout << "\nChecking relationships after first round of unions:" << std::endl;
        std::cout << "Elements 0 and 1 in same set: " << (uf.sameSet(0, 1) ? "Yes" : "No") << std::endl;
        std::cout << "Elements 2 and 3 in same set: " << (uf.sameSet(2, 3) ? "Yes" : "No") << std::endl;
        std::cout << "Elements 0 and 2 in same set: " << (uf.sameSet(0, 2) ? "Yes" : "No") << std::endl;
        
        // Perform more unions to create larger sets
        std::cout << "\nPerforming more unions to create larger sets:" << std::endl;
        
        std::cout << "Union sets containing 1 and 3" << std::endl;
        uf.unionSets(1, 3);  // Now 0,1,2,3 should be in the same set
        
        std::cout << "Union sets containing 5 and 7" << std::endl;
        uf.unionSets(5, 7);  // Now 4,5,6,7 should be in the same set
        
        std::cout << "Union sets containing 7 and 9" << std::endl;
        uf.unionSets(7, 9);  // Now 4,5,6,7,8,9 should be in the same set
        
        // Check set relationships again
        std::cout << "\nChecking relationships after second round of unions:" << std::endl;
        std::cout << "Elements 0 and 3 in same set: " << (uf.sameSet(0, 3) ? "Yes" : "No") << std::endl;
        std::cout << "Elements 4 and 9 in same set: " << (uf.sameSet(4, 9) ? "Yes" : "No") << std::endl;
        std::cout << "Elements 0 and 9 in same set: " << (uf.sameSet(0, 9) ? "Yes" : "No") << std::endl;
        
        // Final union to connect all sets
        std::cout << "\nFinal union to connect all sets:" << std::endl;
        std::cout << "Union sets containing 0 and 4" << std::endl;
        uf.unionSets(0, 4);
        
        // Now all elements should be in the same set
        std::cout << "\nAll elements should now be in the same set:" << std::endl;
        bool allConnected = true;
        for (int i = 0; i < 9; i++) {
            if (!uf.sameSet(i, i+1)) {
                allConnected = false;
                break;
            }
        }
        std::cout << "All elements in the same set: " << (allConnected ? "Yes" : "No") << std::endl;
        
        // Test exception handling
        std::cout << "\nTesting exception handling:" << std::endl;
        std::cout << "Trying to access an out-of-bounds element..." << std::endl;
        uf.find(10);  // Should throw an exception
    }
    catch (const graph::UnionFindException& e) {
        std::cerr << "UnionFind Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}