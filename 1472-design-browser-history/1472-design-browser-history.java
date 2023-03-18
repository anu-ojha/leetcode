class BrowserHistory {
    List<String> record;
    int curIndex = 0;
    public BrowserHistory(String homepage) {
        record = new ArrayList<>();
        record.add(homepage);
        curIndex = 0;
    }

    public void visit(String url) {
        for(int i = record.size() - 1; i > curIndex; i--){
            record.remove(i);
        }
        record.add(url);
        curIndex++;
    }

    public String back(int steps) {
        if(curIndex <= steps){
            curIndex = 0;
        }else{
            curIndex = curIndex - steps;
        }
        return record.get(curIndex);
    }

    public String forward(int steps) {
        int size = record.size();
        if(steps + curIndex < size){
            curIndex += steps;
        }else{
            curIndex = size - 1;
        }
        return record.get(curIndex);
    }
}