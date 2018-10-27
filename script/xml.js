function toMarkdown(json,tag,divid)
{
    $.get("../pic/"+json,function(data){
        var begin=data.indexOf(tag)+tag.length
        console.log(data.length)
        if(begin-tag.length!=-1)
        {
        var end=data.indexOf("end",begin)
        var html = marked(data.substr(begin,end-begin));
         document.getElementById(divid).innerHTML+=html;}
        }
    );
}