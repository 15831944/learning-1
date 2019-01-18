<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="html"></xsl:output>
  <xsl:template match="/">
   <xsl:apply-templates select="tutorial"></xsl:apply-templates>
  </xsl:template>
  <xsl:template match="tutorial">
    <xsl:for-each select="section">
     <h1>
      <xsl:text>Section </xsl:text>
      <xsl:value-of select="position()"/>
      <xsl:text>. </xsl:text>
      <xsl:value-of select="title"/>
     </h1>
     <ul>
      <xsl:for-each select="panel">
        <li>
         <xsl:value-of select="position()"/>
         <xsl:text>. </xsl:text>
         <xsl:value-of select="title"/>
        </li>
      </xsl:for-each>
     </ul>
    </xsl:for-each>
  </xsl:template>
</xsl:stylesheet>