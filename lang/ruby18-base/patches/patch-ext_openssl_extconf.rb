$NetBSD: patch-ext_openssl_extconf.rb,v 1.1 2015/10/14 18:41:42 sevan Exp $

Check for SSLv3 support as it may nolonger be available.

--- ext/openssl/extconf.rb.orig	Sat Oct 10 17:37:29 2015
+++ ext/openssl/extconf.rb
@@ -103,6 +103,9 @@ end
 have_func("SSLv2_method")
 have_func("SSLv2_server_method")
 have_func("SSLv2_client_method")
+have_func("SSLv3_method")
+have_func("SSLv3_server_method")
+have_func("SSLv3_client_method")
 unless have_func("SSL_set_tlsext_host_name", ['openssl/ssl.h'])
   have_macro("SSL_set_tlsext_host_name", ['openssl/ssl.h']) && $defs.push("-DHAVE_SSL_SET_TLSEXT_HOST_NAME")
 end
