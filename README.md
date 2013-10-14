README.txt
==========

This module catches mail and forward them to an pre-configured email-address
At the admin-page the user can configure which modules should forward the mail to
which emailaddress. Also could the user set an prefix which will be added to
the subject.

If the user set the prefix to 123, the subject wil be prefixed with "(123) subject"
This can be handy when there is a development street. You can add for example
the environment.

To test the module add the mailredirect7 module to selected modules and go to the
testpage 'mailredirect7/testform'


Installation
============

Copy the folder mailredirect7 to your module folder and then enable it on the
admin module page. To configure the module go to 'admin/settings/mailredirect7'.


Settings
========

- To who will the redirected mail(s) be send
This is a list of emailaddresses where the mails will be redirected to.
In this textfield you can add more addresses separated by comma's
- Modules
This is the list of modules which implements hook_mail.
You can select which modules should redirect their emails. You can choose to
unselect modules if it's not necessary for some reason.
-Subjectprefix
If you want, you can let the mailredirect prefix the subject by the subjectprefix.
For example, You filled in '123'. The subject will be '(123) {subject}'
This comes in handy when you have different environments. Like a development,
test or acceptance environment.

Author
======

Jop Mesman
