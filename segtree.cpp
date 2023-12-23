template<int (*comb) (int, int), int ID>
struct SegTree {
    int len;
    vector<int> tree;
    SegTree(int size) {
        len = size;
        tree = vector<int> (2*size, ID);
    }
 
    SegTree(vi& a) {
        len = a.size();
        tree = vector<int> (2*len, ID);
        rep (i, len) set(i, a[i]);
    }
 
    void set(int ind, int val) {
        ind += len;
        tree[ind] = val;
        ind /= 2;
        while (ind >= 1) {
            tree[ind] = comb(tree[2*ind], tree[2*ind + 1]);
            ind /= 2;
        }
    }
 
    int get_range(int ind_l, int ind_r) {
        int ans = ID;
        ind_l += len;
        ind_r += len;
        while (ind_l < ind_r) {
            if (ind_l % 2) {
                ans = comb(ans, tree[ind_l]);
                ind_l++;
            }
            if (ind_r % 2) {
                ind_r--;
                ans = comb(ans, tree[ind_r]);
            }
            ind_l /= 2; ind_r /= 2;
        }
        return ans;
    }
 
    void print_tree() {
        rep (i, len) {
            print(get_range(i, i+1), false);
        }
        print();
    }
};