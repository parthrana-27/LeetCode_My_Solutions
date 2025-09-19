class Spreadsheet {
public:
    unordered_map<string,int>ss;
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        ss[cell]=value;
    }
    
    void resetCell(string cell) {
        ss.erase(cell);
    }
    int getValue(string formula) {
        int idx=formula.find('+');
        string l=formula.substr(1,idx-1);
        string r=formula.substr(idx+1);
        int vl=isalpha(l[0]) ? (ss.count(l) ? ss[l] : 0) : stoi(l);
        int vr=isalpha(r[0]) ? (ss.count(r) ? ss[r] : 0) : stoi(r);
        return vl+vr;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */