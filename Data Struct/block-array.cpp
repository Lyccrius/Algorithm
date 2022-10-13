namespace blockArray {
    struct node {
        int val;
        int belong;
    };

    struct block {
        int sum;
        int tag;

        int start;
        int end;
    };

    int n = 1;
    int s = sqrt(n);

    struct node array[n];
    struct node blockArray[s + 1];

    void add(int l, int r, int x) {
        int startBelong = array[l].belong;  
        int endBelong = array[l].belong;

        // The modified interval is contained in the the same block.
        if (startBelong == endBelong) {
            for (int i = l; i <= r; i++) {
                array[i].val += x;
                blockArray[startBelong].sum += x;
                //blockArray[endbelong].sum += x;
            }
            return;
        }

        // The modified interval spans different blocks.

        // Traverse the prefix incomplete block.
        for (int i = l; array[i].belong == startBelong; i++) {
            array[i].val += x;
            blockArray[startBelong].sum += x;
        }
        
        // Traverse the complete block.
        for (int i = startBelong + 1; i < endBelong; i++) {
            blockArray[i].tag += x;
            blockArray[i].sum += x * s;
        }

        // Traverse suffix incomplete blocks.
        for (int i = r; array[i].belong == endBelong; i--) {
            array[i].val += x;
            blockArray[endBelong].sum += x;
        }

        return;
    }
}