var tableOBJ = document.getElementsByClassName("table table-striped table-bordered");
var trOBJ = tableOBJ[0].getElementsByTagName('tr');
var tdOBJ = [];
var step;
for (step = 1; step < trOBJ.length; step++) {
    tdOBJ.push(trOBJ[step].getElementsByTagName('td')[0]);
}

var problemList = [];
for (step = 0; step < tdOBJ.length; step++) {
    problemList.push(parseInt(tdOBJ[step].innerText));
}
problemList

// 위 코드 문제집 콘솔창에 복사 붙여넣기 하면 문제 목록 생성됨.