function getTime() {   
    var dateObj = new Date();
    var year = dateObj.getFullYear();
    var month = dateObj.getMonth()+1;
    var date = dateObj.getDate();
    var day = dateObj.getDay();
    var weeks = ["星期日","星期一","星期二","星期三","星期四","星期五","星期六"];
    var week = weeks[day];
    var hours = dateObj.getHours();
    var minutes = dateObj.getMinutes();
    var seconds = dateObj.getSeconds();

    if(month<10){
        month = "0"+month;
    }
    if(date<10){
        date = "0"+date;
    }
    if(hours<10){
        hours = "0"+hours;
    }
    if(minutes<10){
        minutes = "0"+minutes;
    }
    if(seconds<10){
        seconds = "0"+seconds;
    }

    var newDate = year+"年"+month+"月"+date+"日 "+hours+":"+minutes+":"+seconds+"&nbsp &nbsp"+week;
    document.getElementById("date1").innerHTML = "现在是" + newDate;
    setTimeout('getTime()', 500);
}