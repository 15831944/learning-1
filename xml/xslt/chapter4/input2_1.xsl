<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 <xsl:output method="text"/>
 <xsl:template match="/tutorial">
  <xsl:apply-templates select="*"/>
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
   <xsl:call-template name="message">
   	<xsl:with-param name="type" select="'Even'"/>
   </xsl:call-template>
   <xsl:for-each select="panel">
      <xsl:if test="position() mod 2">
      	<xsl:text>Panel </xsl:text>
      	<xsl:value-of select="position()"/>
      	<xsl:text>=</xsl:text>
      	<xsl:value-of select="title"/>
      	<xsl:text>&#xa;</xsl:text>
      </xsl:if>
   </xsl:for-each>
   <xsl:call-template name="message">
   	<xsl:with-param name="type" select="'Odds'"/>
   </xsl:call-template>
   <xsl:for-each select="panel">
   	  <xsl:if test="not(position() mod 2)">
      	<xsl:text>Panel </xsl:text>
      	<xsl:value-of select="position()"/>
      	<xsl:text>=</xsl:text>
      	<xsl:value-of select="title"/>
      	<xsl:text>&#xa;</xsl:text>   		
   	  </xsl:if>
   </xsl:for-each>
 </xsl:template>
</xsl:stylesheet>