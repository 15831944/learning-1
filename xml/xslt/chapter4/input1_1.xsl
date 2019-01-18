<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 <xsl:output method="html"></xsl:output>
 <xsl:template match="/tutorial">
  <xsl:apply-templates select="section"/>
 </xsl:template>
 <xsl:template match="section">
  <xsl:text> Section </xsl:text>
  <xsl:value-of select="position()"/>
  <xsl:text>. </xsl:text>
  <xsl:value-of select="title"/>
  <xsl:text>&#xa;</xsl:text>
  <xsl:for-each select="panel">
   <panel>
     <xsl:text> Panel </xsl:text>
     <xsl:value-of select="position()"/>
     <xsl:text>=</xsl:text>
     <xsl:value-of select="title"/>
   </panel>
    <xsl:text>&#xa;</xsl:text>
  </xsl:for-each>
 </xsl:template>
</xsl:stylesheet>