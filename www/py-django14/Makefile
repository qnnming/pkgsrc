# $NetBSD: Makefile,v 1.15 2016/08/28 15:48:36 wiz Exp $

DISTNAME=	Django-1.4.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework (LTS version)
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty
REPLACE_PYTHON=		${WRKSRC}/django/bin/*.py
REPLACE_PYTHON+=	${WRKSRC}/django/bin/profiling/*.py
REPLACE_PYTHON+=	${WRKSRC}/django/contrib/admin/bin/*.py
REPLACE_PYTHON+=	${WRKSRC}/django/contrib/admin/static/admin/js/*.py
REPLACE_PYTHON+=	${WRKSRC}/django/conf/project_template/*.py

PYTHON_VERSIONED_DEPENDENCIES=	flup
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # use py-django if you want python-3.x support

.include "options.mk"

pre-configure:
.if empty(PKG_OPTIONS:Mmysql)
	rm -r ${WRKSRC}/django/db/backends/mysql
.endif
.if empty(PKG_OPTIONS:Moracle)
	rm -r ${WRKSRC}/django/db/backends/oracle
.endif
.if empty(PKG_OPTIONS:Mpgsql)
	rm -r ${WRKSRC}/django/db/backends/postgresql_psycopg2
.endif
.if empty(PKG_OPTIONS:Msqlite)
	rm -r ${WRKSRC}/django/db/backends/sqlite3
.endif

BACKEND_PATH=		${PYSITELIB}/django/db/backends
BACKEND_PATH_PLIST=	$${PYSITELIB}/django/db/backends

PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/mysql/", "$${PLIST.mysql}${BACKEND_PATH_PLIST}/mysql/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/oracle/", "$${PLIST.oracle}${BACKEND_PATH_PLIST}/oracle/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/postgresql_psycopg2/", "$${PLIST.pgsql}${BACKEND_PATH_PLIST}/postgresql_psycopg2/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/sqlite3/", "$${PLIST.sqlite}${BACKEND_PATH_PLIST}/sqlite3/") }

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
