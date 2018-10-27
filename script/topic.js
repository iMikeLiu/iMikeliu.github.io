function chk(data)
{
	var text =$("#"+data).val();
$.get("/markdown/"+text+".md",function(data){
 	document.getElementById("Text").innerHTML=data;}
);
}
function GetQueryString(name) {  
	var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)"); 
	var r = window.location.search.substr(1).match(reg);  
	 
	if (r != null) 
		return decodeURIComponent(r[2]); 
	else
		return null;  
  }  

function topic()
{	var strUrl=window.location.href;
	var arrUrl=strUrl.split("/");
	var strPage=arrUrl[arrUrl.length-1];
	var strr=strPage.split(".");
	document.title=strr[0];
	$.get("/topic/"+strr[0]+".top",function(data){

	document.getElementById("topic").innerHTML=('<h1 style="text-align: center;">'+data+'</h1>');
	});
}