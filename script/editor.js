function chk(data)
{
	var text =$("#"+data).val();
$.get("/markdown/"+text+".md",function(data){
 	document.getElementById("Text").innerHTML=data;}
);
}