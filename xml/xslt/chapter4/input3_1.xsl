<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 <xsl:output method="text"/>
 <xsl:template match="/tutorial">
<!--   <xsl:apply-templates select="section/panel"/>
  <xsl:apply-templates select="section/newOne"/> -->
  <xsl:apply-templates select="section"/>
 </xsl:template>
 <xsl:template name="message">
 	<xsl:param name="type" select="All"/>
	<xsl:text>&#xa;</xsl:text>
	<xsl:value-of select="$type"/>
   <xsl:text>=&#xa;</xsl:text>
 </xsl:template>
 <xsl:template match="*[contains(local-name(),'section')]">
   <xsl:text>Section </xsl:text>
   <xsl:value-of select="position()"/>
   <xsl:text>=</xsl:text>
   <xsl:value-of select="title"/>
   <xsl:apply-templates select="panel"/>
   <xsl:apply-templates select="newOne"/>
 </xsl:template>
 <xsl:template match="panel">
   	<xsl:text>&#xa;Panel </xsl:text>
   	<xsl:value-of select="position()"/>
   	<xsl:text>=</xsl:text>
   	<xsl:value-of select="title"/>
 </xsl:template>
 <xsl:template match="newOne">
    <xsl:call-template name="panel1"/>
 </xsl:template>
 <xsl:template name="panel1">
 	<xsl:text>&#xa;Other =</xsl:text>
    <xsl:value-of select="panel/other"></xsl:value-of>
    <xsl:text>&#xa;New = </xsl:text>
    <xsl:value-of select="panel/new"></xsl:value-of>
 </xsl:template>
</xsl:stylesheet>