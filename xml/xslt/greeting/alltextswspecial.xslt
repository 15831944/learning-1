<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 <xsl:output method="html"></xsl:output>
 <xsl:strip-space elements="*"></xsl:strip-space>
 <xsl:preserve-space elements="greeting"></xsl:preserve-space>
 <xsl:template match="/">
  <html>
   <body>
    <xsl:apply-templates select="/root/text()"></xsl:apply-templates>
   </body>
  </html>
 </xsl:template>
 <xsl:template match="text()">
    <h1>
     text=<xsl:value-of select="."></xsl:value-of>
    </h1>
 </xsl:template>
 <xsl:template match="greeting">
     <h1>
      greetings!!
      <xsl:value-of select="."></xsl:value-of>
     </h1>
  </xsl:template>
</xsl:stylesheet>
