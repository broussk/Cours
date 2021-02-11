function selection(i) {
    for(j = 1; j <= 10; j++) {
        if(j == i)
            $('#table' + j).show();
        else
            $('#table' + j).hide();
    }
}