#include <stdio.h>
#include <stdlib.h>

//
// we do two things with this program
//
// 1. We take the template file and insert the guts of the html file in it
// 2. We add case_study[] at the right place in case-studies.html
//

// offset into front to file title line
#define TITLE_OFFSET 6

// path to DreamweaverBootstrap - note no trailing /
#define DW_PATH "/sdb1/DreamweaverBootstrap"
// path to hugo - note again no trailing /
#define HUG_PATH "/sdb1/one-click-hugo-cms"
// path to <file>.md - no trailling /
#define HUG_MD_PATH (HUG_PATH "/" "site/content/post/%s.md")
// path to <file>.html - note no trailing /
#define HUG_HTML_PATH (HUG_PATH "/" "site/public/post/%s/index.html")
// path to case_studies.html - no trailing /
#define CAS_PATH (DW_PATH" "/" casestudies/case-studies.html")
// path to <file>.html - no trailing /
#define DW_HTML_PATH (DW_PATH "/" "casestudies/%s.html")

// find string in CAS_PATH and place case_study[] before here
#define AF "<!-- Place Page Contents Before Here -->"

char *front[] = {
  "<!DOCTYPE html>",
  "<html lang=\"en\">",
  "<head>",
  "<meta charset=\"utf-8\">",
  "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">",
  "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">",
  "<title>template</title>",
  "",
  "<link href=\"../css/main.125b5-formatted.css\" rel=\"stylesheet\">",
  "<!-- Bootstrap -->",
  "<link href=\"../css/bootstrap-4.4.1.css\" rel=\"stylesheet\">",
  "</head>",
  "",
  "<body>",
  "",
  "<nav class=\"navbar navbar-expand-lg navbar-dark bg-dark\"> <a class=\"navbar-brand\" href=\"/\" style=\"color: red\">RedFire</a>",
  "<button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\"> <span class=\"navbar-toggler-icon\"></span> </button>",
  "<div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">",
  "<ul class=\"navbar-nav mr-auto\">",
  "<li class=\"nav-item active\"> <a class=\"nav-link\" href=\"/\">Home</a> </li>",
  "<li class=\"nav-item active\"> <a class=\"nav-link\" href=\"/casestudies/case-studies.html\">CaseStudies</a> </li>",
  "</ul>",
  "</div>",
  "</nav>",
  NULL };

char *back[] = {
  "<footer class=\"text-center\">",
  "<div class=\"container\">",
  "<div class=\"row\">",
  "<div class=\"col-12\">",
  "<p>Copyright © RedFire Consultants. All rights reserved.</p>",
  "</div>",
  "</div>",
  "</div>",
  "</footer>",
  "",
  "<!-- jQuery (necessary for Bootstrap's JavaScript plugins) --> ",
  "<script src=\"../js/jquery-3.4.1.min.js\"></script>",
  "",
  "<!-- Include all compiled plugins (below), or include individual files as needed --> ",
  "<script src=\"../js/popper.min.js\"></script>",
  "<script src=\"../js/bootstrap-4.4.1.js\"></script>",
  "</body>",
  "</html>",
  NULL };

#if 0
  EXAMPLE - fill in the %s as indicated in case_study
      <h2 class="f3 b lh-title mb1 primary">The Case of Poor Client Relations.</h2>
      <p class="mid-gray lh-title mb2">Sun, Jan 30, 2022</p>
      <p class="mb0">In this case, the vendor-customer relationship had to change.</p>
      <p class="link b dib black mb0">Read more →</p>
      </a> </div>
#endif // 0

    // we will also have to pull title, date, and description out of the top of the .md file
    // and put it in case_study[].
    // here is a sample of what we'll fine
#if 0
---
title: 'The Case of the Missing Architect.'
date: 2022-01-20T09:15:00.000Z
draft: false
description: >-
  In this case, we visit a sub-contractor working on an interface to a telephone switch for a much larger client.
---
#endif // 0

char *case_study[] = {
  "<div class=\"w-50-ns ph1-ns flex\"> <a href=\"/casestudies/%s.html\" class=\"no-underline pa3 bg-grey-1 br1 mb2 db raise w-100\">",
  "<h2 class=\"f3 b lh-title mb1 primary\">%s</h2>",
  "<p class=\"mid-gray lh-title mb2\">%s</p>",
  "<p class=\"mb0\">%s</p>",
  "<p class=\"link b dib black mb0\">Read more →</p>",
  "</a> </div>",
  NULL };
