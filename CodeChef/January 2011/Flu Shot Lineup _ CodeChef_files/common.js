function displayRecentTimeoutError(request, errorType, errorThrown) {
	try {
	    if (errorType == 'timeout') {
	      // do sonething here
	      $("#statusdiv").html("<center>Oops, we couldn't seem to load the site's recent activity.  Try again soon.</center>");
	    }
	}
  	catch (e) {}
}

function displaySsubmisisonTimeOutError(request, errorType, errorThrown) {
	try {
	    if (errorType == 'timeout') {
	      // do sonething here
	      $("#rankContentDiv").html("<center>Oops, we couldn't seem to load the successfull submission.  Try again soon.</center>");
	    }
	}
  	catch (e) {}
}

function displayRanksTimeoutError(request, errorType, errorThrown) {
	try {
	    if (errorType == 'timeout') {
	      // do sonething here
	      $("#rankdiv").html("<center>Oops, we couldn't seem to load the ranks.  Try again soon.</center>");
	    }
	}
  	catch (e) {}
}

function displayTRanksTimeoutError(request, errorType, errorThrown) {
	try {
	    if (errorType == 'timeout') {
	      // do sonething here
	      $("#trankdiv").html("<center>Oops, we couldn't seem to load the ranks.  Try again soon.</center>");
	    }
	}
  	catch (e) {}
}

$("#recentPreviousButtonactive").click(previous);
function previous(){
	$("#ajaxProgressDiv").show();
	var originalstart = $("#recentStart").val();
	var originalcount = $("#recentCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentCount").val();
	var userid = $('#userid').val();
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: "/ajax/recent/"+start+"/"+count+"/",
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}
$("#recentNextButtonactive").click(next);
function next(){
	$("#ajaxProgressDiv").show();
	var start = $("#recentStart").val();
	var count = $("#recentCount").val();
	var userid = $('#userid').val();
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: "/ajax/recent/"+start+"/"+count+"/",
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}







$("#recentContestPreviousButtonactive").click(Contestprevious);
function Contestprevious(){
	$("#ContestajaxProgressDiv").show();
	var originalstart = $("#ContestrecentStart").val();
	var originalcount = $("#ContestrecentCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#ContestrecentCount").val();
	var userid = $('#userid').val();
	
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: "/ajax/recent/contest/"+$(this).attr('class')+"/"+start+"/"+count+"/",
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}
$("#recentContestNextButtonactive").click(Contestnext);
function Contestnext(){
	$("#ContestajaxProgressDiv").show();
	var start = $("#ContestrecentStart").val();
	var count = $("#ContestrecentCount").val();
	var userid = $('#userid').val();
	
	//This is for first time ajax call
	if(!$(this).attr('class')){
		ajaxurl = "/ajax/recent/contest/"+$("#contestCodeRecentContest").val()+"/"+start+"/"+count+"/";
	}else{
		ajaxurl = "/ajax/recent/contest/"+$(this).attr('class')+"/"+start+"/"+count+"/";
	}
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: ajaxurl,
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}







$("#recentProblemPreviousButtonactive").click(recentProblemprevious);
function recentProblemprevious(){
	$("#recentProblemajaxProgressDiv").show();
	var originalstart = $("#recentProblemStart").val();
	var originalcount = $("#recentProblemCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentProblemCount").val();
	var userid = $('#userid').val();
	if($("#pagename").val() == 'fullProblemStatus'){
		$.ajax({
			type: "POST",
			url: "/ajax/recent/practice/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: "/ajax/recent/practice/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			cache: false,
			timeout: 10000,
			data: "userid="+userid,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}
$("#recentProblemNextButtonactive").click(recentProblemnext);
function recentProblemnext(){
	$("#recentProblemajaxProgressDiv").show();
	var start = $("#recentProblemStart").val();
	var count = $("#recentProblemCount").val();
	var userid = $('#userid').val();
	//This is for first time ajax call
	if(!$(this).attr('class')){
		ajaxurl = "/ajax/recent/practice/"+$("#problemCodeRecentPractice").val()+"/"+start+"/"+count+"/";
	}else{
		ajaxurl = "/ajax/recent/practice/"+$(this).attr('class')+"/"+start+"/"+count+"/";
	}
	if($("#pagename").val() == 'fullProblemStatus'){
		$.ajax({
			type: "POST",
			url: ajaxurl,
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: ajaxurl,
			cache: false,
			timeout: 10000,
			data: "userid="+userid,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}


/* ################################################################################## */

$("#recentPractpreviousButtonactive").click(recentPractprevious);
function recentPractprevious(){
	$("#recentPrctajaxProgressDiv").show();
	var originalstart = $("#recentPractStart").val();
	var originalcount = $("#recentPractCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentPractCount").val();
	var userid = $('#userid').val();
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: "/ajax/recent/practice/"+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}
$("#recentPractnextButtonactive").click(recentPractnext);
function recentPractnext(){
	$("#recentPrctajaxProgressDiv").show();
	var start = $("#recentPractStart").val();
	var count = $("#recentPractCount").val();
	var userid = $('#userid').val();
	$.ajax({
		type:"POST",
		data: "userid="+userid,
		url: "/ajax/recent/practice/"+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});
}

/* ################################################################################## */


$("#recentContestProblemPreviousButtonactive").click(recentContestProblemprevious);
function recentContestProblemprevious(){
	$("#recentContestProblemajaxProgressDiv").show();
	var originalstart = $("#recentContestProblemStart").val();
	var originalcount = $("#recentContestProblemCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentContestProblemCount").val();
	var userid = $('#userid').val();
	classvalue = $(this).attr('class');
	classarray = classvalue.split(' ');
	
	
	if($("#pagename").val() == 'fullProblemStatus'){
		$.ajax({
			type: "POST",
			url: "/ajax/recent/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: "/ajax/recent/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
			cache: false,
			timeout: 10000,
			data: "userid="+userid,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}
$("#recentContestProblemNextButtonactive").click(recentContestProblemnext);
function recentContestProblemnext(){
	$("#recentContestProblemajaxProgressDiv").show();
	var start = $("#recentContestProblemStart").val();
	var count = $("#recentContestProblemCount").val();
	var userid = $('#userid').val();
	if($(this).attr('class')){
		classvalue = $(this).attr('class');
	}else{
		classvalue = $("#contestCodeRecentContestProblem").val();
	}
	classarray = classvalue.split(' ');
	
	if($("#pagename").val() == 'fullProblemStatus'){
		$.ajax({
			type: "POST",
			url: "/ajax/recent/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: "/ajax/recent/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
			cache: false,
			timeout: 10000,
			data: "userid="+userid,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}









$("#recentUserPreviousButtonactive").click(previousUser);
function previousUser(){
	$("#ajaxUserProgressDiv").show();
	var originalstart = $("#recentUserStart").val();
	var originalcount = $("#recentUserCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentUserCount").val();
	if($("#pagename").val() == 'fullUserStatus'){
		$.ajax({
			type: "POST",
			url: "/ajax/recent/user/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			data: "detail=yes",
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			url: "/ajax/recent/user/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}
$("#recentUserNextButtonactive").click(nextUser);
function nextUser(){
	$("#ajaxUserProgressDiv").show();
	var start = $("#recentUserStart").val();
	var count = $("#recentUserCount").val();
	if($("#pagename").val() == 'fullUserStatus'){
		$.ajax({
			type: "POST",
			url: "/ajax/recent/user/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			data: "detail=yes",
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}else{
		$.ajax({
			url: "/ajax/recent/user/"+$(this).attr('class')+"/"+start+"/"+count+"/",
			cache: false,
			timeout: 10000,
			success: function(html){
				$("#statusdiv").html(html);
			},
			error: displayRecentTimeoutError,
		});
	}
}














$("#ssubmissionsPreviousButtonactive").click(ssubmissionsPrevious);
function ssubmissionsPrevious(){
	$("#ssubmissionsAjaxProgressDiv").show();
	var originalstart = $("#ssubmissionsStart").val();
	var originalcount = $("#ssubmissionsCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#ssubmissionsCount").val();
	var userid = $("#userid").val();
	if($("#pagename").val() == 'fullProblemRank'){
		$.ajax({
			type: "POST",
			url: "/ajax/ssubmissions/practice/"+$(this).attr('class')+'/'+start+"/"+count+"/",
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 20000,
			success: function(html){
				$("#rankContentDiv").html(html);
			},
			error: displaySsubmisisonTimeOutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: "/ajax/ssubmissions/practice/"+$(this).attr('class')+'/'+start+"/"+count+"/",
			cache: false,
			timeout: 20000,
			data: "userid="+userid,
			success: function(html){
				$("#rankContentDiv").html(html);
			},
			error: displaySsubmisisonTimeOutError,
		});
	}
}
$("#ssubmissionsNextButtonactive").click(ssubmissionsNext);
function ssubmissionsNext(){
	$("#ssubmissionsAjaxProgressDiv").show();
	var start = $("#ssubmissionsStart").val();
	var count = $("#ssubmissionsCount").val();
	var userid = $("#userid").val();
	//This is for first time ajax call
	if(!$(this).attr('class')){
		ajaxurl = "/ajax/ssubmissions/practice/"+$("#problemCodeSsubPractice").val()+'/'+start+"/"+count+"/";
	}else{
		ajaxurl = "/ajax/ssubmissions/practice/"+$(this).attr('class')+'/'+start+"/"+count+"/";
	}
	if($("#pagename").val() == 'fullProblemRank'){
		$.ajax({
			type: "POST",
			url: ajaxurl,
			data: "detail=yes&userid="+userid,
			cache: false,
			timeout: 20000,
			success: function(html){
				$("#rankContentDiv").html(html);
			},
			error: displaySsubmisisonTimeOutError,
		});
	}else{
		$.ajax({
			type: "POST",
			url: ajaxurl,
			cache: false,
			timeout: 20000,
			data: "userid="+userid,
			success: function(html){
				$("#rankContentDiv").html(html);
			},
			error: displaySsubmisisonTimeOutError,
		});
	}
		
}










$("#UserSsubmissionsPreviousButtonactive").click(UserSsubmissionsPrevious);
function UserSsubmissionsPrevious(){
	$("#UserSsubmissionsAjaxProgressDiv").show();
	var originalstart = $("#UserSsubmissionsStart").val();
	var originalcount = $("#UserSsubmissionsCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#UserSsubmissionsCount").val();
	$.ajax({
		url: "/ajax/ssubmissions/user/practice/"+$(this).attr('class')+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}
$("#UserSsubmissionsNextButtonactive").click(UserSsubmissionsNext);
function UserSsubmissionsNext(){
	$("#UserSsubmissionsAjaxProgressDiv").show();
	var start = $("#UserSsubmissionsStart").val();
	var count = $("#UserSsubmissionsCount").val();
	$.ajax({
		url: "/ajax/ssubmissions/user/practice/"+$(this).attr('class')+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}













$("#ssubmissionsContestPreviousButtonactive").click(ssubmissionsContestPrevious);
function ssubmissionsContestPrevious(){
	$("#ssubmissionsAjaxProgressDiv").show();
	var originalstart = $("#ssubmissionsContestStart").val();
	var originalcount = $("#ssubmissionsContestCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#ssubmissionsContestCount").val();
	var userid = $("#userid").val();
	classvalue = $(this).attr('class');
	classarray = classvalue.split(' ');
	$.ajax({
		type: "POST",
		url: "/ajax/ssubmissions/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}
$("#ssubmissionsContestNextButtonactive").click(ssubmissionsContestNext);
function ssubmissionsContestNext(){
	$("#ssubmissionsAjaxProgressDiv").show();
	var start = $("#ssubmissionsContestStart").val();
	var count = $("#ssubmissionsContestCount").val();
	var userid = $("#userid").val();
	if($(this).attr('class')){
		classvalue = $(this).attr('class');
	}else{
		classvalue = $("#contestCodeSsubContestProblem").val();
	}
	classarray = classvalue.split(' ');
	$.ajax({
		type: "POST",
		url: "/ajax/ssubmissions/contest/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}





$("#PSubmissionsUserPreviousButtonactive").click(PSubmissionsUserPrevious);
function PSubmissionsUserPrevious(){
	$("#PSubmissionsUserAjaxProgressDiv").show();
	var originalstart = $("#PSubmissionsUserStart").val();
	var originalcount = $("#PSubmissionsUserCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#PSubmissionsUserCount").val();
	var userid = $("#userid").val();
	classvalue = $(this).attr('class');
	classarray = classvalue.split('-');
	$.ajax({
		type: "POST",
		url: "/ajax/user/problem/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}
$("#PSubmissionsUserNextButtonactive").click(PSubmissionsUserNext);
function PSubmissionsUserNext(){
	$("#PSubmissionsUserAjaxProgressDiv").show();
	var start = $("#PSubmissionsUserStart").val();
	var count = $("#PSubmissionsUserCount").val();
	var userid = $("#userid").val();
	classvalue = $(this).attr('class');
	classarray = classvalue.split('-');
	$.ajax({
		type: "POST",
		url: "/ajax/user/problem/"+classarray[0]+'/'+classarray[1]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#rankContentDiv").html(html);
		},
		error: displaySsubmisisonTimeOutError,
	});
}









$("#contestRanksPreviousButtonactive").click(contestRanksPrevious);
function contestRanksPrevious(){
	$("#contestRanksAjaxProgressDiv").show();
	var originalstart = $("#contestRanksStart").val();
	var originalcount = $("#contestRanksCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#contestRanksCount").val();
	
	classvalue = $("#contestCodeRanksContest").val();
	
	$.ajax({
		url: "/ajax/ranks/contest/"+classvalue+"/"+start+"/"+count+"/",
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#rankdiv").html(html);
		},
		error: displayRanksTimeoutError
	});
}
$("#contestRanksNextButtonactive").click(contestRanksNext);
function contestRanksNext(){
	$("#contestRanksAjaxProgressDiv").show();
	var start = $("#contestRanksStart").val();
	var count = $("#contestRanksCount").val();
	
	classvalue = $("#contestCodeRanksContest").val();

	$.ajax({
		url: "/ajax/ranks/contest/"+classvalue+"/"+start+"/"+count+"/",
		cache: false,
		timeout: 30000,
		success: function(html){
			$("#rankdiv").html(html);
		},
		error: displayRanksTimeoutError
	});
}

//Team Additions
$("#tcontestRanksPreviousButtonactive").click(tcontestRanksPrevious);
function tcontestRanksPrevious(){
    $("#tcontestRanksAjaxProgressDiv").show();
    var originalstart = $("#tcontestRanksStart").val();
    var originalcount = $("#tcontestRanksCount").val();
    var start = ( originalstart - originalcount - originalcount);
    var count = $("#tcontestRanksCount").val();
    
    classvalue = $("#tcontestCodeRanksContest").val();
    
    $.ajax({
	url: "/ajax/ranks/tcontest/"+classvalue+"/"+start+"/"+count+"/",
	   cache: false,
	   timeout: 30000,
	   success: function(html){
	       $("#trankdiv").html(html);
	   },
	   error: displayTRanksTimeoutError
    });
}
$("#tcontestRanksNextButtonactive").click(tcontestRanksNext);
function tcontestRanksNext(){
    $("#tcontestRanksAjaxProgressDiv").show();
    var start = $("#tcontestRanksStart").val();
    var count = $("#tcontestRanksCount").val();
    
    classvalue = $("#tcontestCodeRanksContest").val();
    
    $.ajax({
	url: "/ajax/ranks/tcontest/"+classvalue+"/"+start+"/"+count+"/",
	   cache: false,
	   timeout: 30000,
	   success: function(html){
	       $("#trankdiv").html(html);
	   },
	   error: displayTRanksTimeoutError
    });
}

$("#tcontestRanksPreviousButtonactive").click(etcontestRanksPrevious);
function etcontestRanksPrevious(){
    $("#tcontestRanksAjaxProgressDiv").show();
    var originalstart = $("#tcontestRanksStart").val();
    var originalcount = $("#tcontestRanksCount").val();
    var start = ( originalstart - originalcount - originalcount);
    var count = $("#tcontestRanksCount").val();
    
    classvalue = $("#tcontestCodeRanksContest").val();
    
    $.ajax({
	url: "/ajax/ranks/etcontest/"+classvalue+"/"+start+"/"+count+"/",
	   cache: false,
	   timeout: 10000,
	   success: function(html){
	       $("#trankdiv").html(html);
	   },
	   error: displayTRanksTimeoutError
    });
}
$("#tcontestRanksNextButtonactive").click(etcontestRanksNext);
function etcontestRanksNext(){
    $("#tcontestRanksAjaxProgressDiv").show();
    var start = $("#tcontestRanksStart").val();
    var count = $("#tcontestRanksCount").val();
    
    classvalue = $("#tcontestCodeRanksContest").val();
    
    $.ajax({
	url: "/ajax/ranks/etcontest/"+classvalue+"/"+start+"/"+count+"/",
	   cache: false,
	   timeout: 10000,
	   success: function(html){
	       $("#trankdiv").html(html);
	   },
	   error: displayTRanksTimeoutError
    });
}

//team additions end



$("#contestCountryRanksPreviousButtonactive").click(contestCountryRanksPrevious);
function contestCountryRanksPrevious(){
	$("#contestRanksAjaxProgressDiv").show();
	var originalstart = $("#contestRanksStart").val();
	var originalcount = $("#contestRanksCount").val();
	
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#contestRanksCount").val();
	
	classvalue = $("#contestCodeRanksContest").val();
	classarray = classvalue.split(' ');
	$.ajax({
		url: "/ajax/ranks/country/contest/"+classarray[0]+"/"+classarray[1]+"/"+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#rankdiv").html(html);
		},
		error: displayRanksTimeoutError
	});
}
$("#contestCountryRanksNextButtonactive").click(contestCountryRanksNext);
function contestCountryRanksNext(){
	$("#contestRanksAjaxProgressDiv").show();
	var start = $("#contestRanksStart").val();
	var count = $("#contestRanksCount").val();
	
	classvalue = $("#contestCodeRanksContest").val();
	classarray = classvalue.split(' ');
	
	//This is for first time ajax call
	if(!$(this).attr('class')){
		ajaxurl = "/ajax/ranks/country/contest/"+classarray[0]+"/"+classarray[1]+"/"+start+"/"+count+"/";
	}else{
		ajaxurl = "/ajax/ranks/country/contest/"+classarray[0]+"/"+classarray[1]+"/"+start+"/"+count+"/";
	}
	$.ajax({
		url: ajaxurl,
		cache: false,
		timeout: 10000,
		success: function(html){
			$("#rankdiv").html(html);
		},
		error: displayRanksTimeoutError
	});
}


$("#recentUserContestProblemPreviousButtonactive").click(recentUserContestProblemprev);
function recentUserContestProblemprev(){
	$("#recentUserContestProblemajaxProgressDiv").show();
	var originalstart = $("#recentUserContestProblemStart").val();
	var originalcount = $("#recentUserContestProblemCount").val();
	var start = ( originalstart - originalcount - originalcount);
	var count = $("#recentUserContestProblemCount").val();
	var userid = $("#userid").val();
	classvalue = $(this).attr('class');
	classarray = classvalue.split(' ');
	$.ajax({
		type:"POST",
		url: "/ajax/user/contest/problem/"+classarray[0]+'/'+classarray[1]+'/'+classarray[2]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});	
}

$("#recentUserContestProblemNextButtonactive").click(recentUserContestProblemnext);
function recentUserContestProblemnext() {
	$("#recentUserContestProblemajaxProgressDiv").show();
	var start = $("#recentUserContestProblemStart").val();
	var count = $("#recentUserContestProblemCount").val();
	var userid = $("#userid").val();
	
	classvalue = $(this).attr('class');
	classarray = classvalue.split(' ');
	$.ajax({
		type:"POST",
		url: "/ajax/user/contest/problem/"+classarray[0]+'/'+classarray[1]+'/'+classarray[2]+'/'+start+"/"+count+"/",
		cache: false,
		timeout: 10000,
		data: "userid="+userid,
		success: function(html){
			$("#statusdiv").html(html);
		},
		error: displayRecentTimeoutError,
	});	
	
}
