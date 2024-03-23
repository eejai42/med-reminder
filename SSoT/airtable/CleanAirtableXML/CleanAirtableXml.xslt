<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:json="http://james.newtonking.com/projects/json">
    <xsl:output method="xml" indent="yes" />

    <xsl:template match="node()|@*">
        <xsl:copy>
            <xsl:apply-templates select="node()|@*"/>
        </xsl:copy>
    </xsl:template>
    <!-- Root template -->
    <xsl:template match="/">
        <FileSet>
            <FileSetFiles>
                <FileSetFile>
                    <RelativePath>../../MedReminder.xml</RelativePath>
                    <FileContents>
                        <MedReminder>
                            <Constants>
                                <xsl:for-each select="/*/Constants/Constant">
                                    <xsl:sort select="Category" data-type="text" />
                                    <xsl:sort select="SortOrder" data-type="number"/>
                                    <xsl:apply-templates select="." />
                                </xsl:for-each>
                            </Constants>
                            <PartTypes>
                                <xsl:for-each select="/*/PartTypes/PartType[QuantityNeeded>0]">
                                    <xsl:sort select="Name" />
                                    <xsl:apply-templates select="." />
                                </xsl:for-each>
                            </PartTypes>
                            <FSMs>
                                <xsl:apply-templates select="/*/FSMs/FSM" />
                            </FSMs>
                            <MachineStates>
                                <xsl:for-each select="/*/MachineStates/MachineState">
                                    <xsl:sort select="SortOrder" data-type="number" />
                                    <xsl:apply-templates select="." />
                                </xsl:for-each>
                            </MachineStates>
                            <!-- <Parts>
                                <xsl:for-each select="/*/Parts/Part[Quantity > 0]">
                                    <xsl:sort select="Name" />
                                    <xsl:apply-templates select="." />
                                </xsl:for-each>
                            </Parts>
                            <PartLinks>
                                <xsl:apply-templates select="/*/PartLinks" />
                            </PartLinks>
                            <Entities>
                                <xsl:apply-templates select="/*/Entities/Entity" />
                            </Entities> -->
                        </MedReminder>
                    </FileContents>
                </FileSetFile>
            </FileSetFiles>
        </FileSet>
    </xsl:template>

 <!-- Template for each FSM -->
    <xsl:template match="FSM">
        <FSM>
            <Name>
                <xsl:value-of select="Name"/>
            </Name>
            <InitialStateName>
                <xsl:value-of select="InitialStateName"/>
            </InitialStateName>
        </FSM>
    </xsl:template>

    <!-- Template for each MachineState -->

    <!-- Template for MachineState -->
    <xsl:template match="MachineState">
        <MachineState>
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <!-- Include other relevant fields from MachineState -->
            <FromTransitions>
                <!-- FromTransitions -->
                <xsl:for-each select="//Transition[FromState=current()/MachineStateId]">
                    <xsl:sort select="SortOrder" data-type="number" />
                    <FromTransition json:Array="true">
                        <Description><xsl:value-of select="Description"/></Description>
                        <ActionName><xsl:value-of select="ActionName"/></ActionName>
                        <ToStateName><xsl:value-of select="ToStateName"/></ToStateName>
                        <Name><xsl:value-of select="Name"/></Name>
                        <!-- Include other relevant fields from Transition -->
                    </FromTransition>
                </xsl:for-each>
            </FromTransitions>
            <ToTransitions>
                <!-- ToTransitions -->
                <xsl:for-each select="//Transition[ToState=current()/MachineStateId]">
                <xsl:sort select="SortOrder" data-type="number" />
                <ToTransition  json:Array="true">
                    <Description><xsl:value-of select="Description"/></Description>
                    <ActionName><xsl:value-of select="ActionName"/></ActionName>
                    <FromStateName><xsl:value-of select="FromStateName"/></FromStateName>
                    <Name><xsl:value-of select="Name"/></Name>
                    <!-- Include other relevant fields from Transition -->
                </ToTransition>
            </xsl:for-each>
            </ToTransitions>
        </MachineState>        
    </xsl:template>

     <!-- Template for PartType -->
     <xsl:template match="PartType">
        <PartType json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <QuantityNeeded><xsl:value-of select="QuantityNeeded"/></QuantityNeeded>
            <CountAllLinkToParts><xsl:value-of select="CountAllLinkToParts"/></CountAllLinkToParts>
            <CountAllLinkFromParts><xsl:value-of select="CountAllLinkFromParts"/></CountAllLinkFromParts>
            <Parts>
                <xsl:for-each select="//Part[PartType=current()/PartTypeId and Quantity > 0]">
                    <xsl:sort select="Name" />
                    <xsl:apply-templates select="." />
                </xsl:for-each>
            </Parts>
        </PartType>
    </xsl:template>

    <xsl:template match="Constant">
        <Constant json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <xsl:for-each select="*[not(self::Name) and not(self::Description) and 
                                    not(self::SortOrder) and not(self::ConstantId) and
                                    not(self::createdTime)]">
                <xsl:element name="{name()}">
                    <xsl:value-of select="."/>
                </xsl:element>  
            </xsl:for-each>
            
        </Constant>
    </xsl:template>

    <xsl:template match="Part">
        <Part json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <PartIndex><xsl:value-of select="PartIndex"/></PartIndex>
            <Color><xsl:value-of select="Color"/></Color>
            <Quantity><xsl:value-of select="Quantity"/></Quantity>
            <Purpose><xsl:value-of select="Purpose"/></Purpose>
            <!-- Additional Part details can be listed here -->
            <!-- If needed, embed PartType details -->
            <xsl:if test="PartType">
                <PartType>
                    <!-- This assumes you can fetch the PartType details based on the PartTypeId -->
                    <Name><xsl:value-of select="//PartType[PartTypeId=current()/PartType]/Name"/></Name>
                    <QuantityNeeded><xsl:value-of select="//PartType[PartTypeId=current()/PartType]/QuantityNeeded"/></QuantityNeeded>
                    <!-- Embedding Parts within PartType might not make sense in this context and could lead to recursive structures -->
                </PartType>
            </xsl:if>
            <FromPartLinks>
                <xsl:apply-templates select="//PartLink[FromPart=current()/PartId]" mode="from"/>
            </FromPartLinks>
            <ToPartLinks>
                <xsl:apply-templates select="//PartLink[ToPart=current()/PartId]" mode="to"/>
            </ToPartLinks>

        </Part>
    </xsl:template>

    <!-- Template for each PartLink when coming from this Part -->
    <xsl:template match="PartLink" mode="from">
        <PartLink json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <!-- Include FromPart details -->
            <LowerVariableName><xsl:value-of select="LowerVairableName"/></LowerVariableName>
            <FromPartName><xsl:value-of select="FromPartName"/></FromPartName>
            <!-- Additional ToPartLink details -->
            <FromPartColor><xsl:value-of select="FromPartColor"/></FromPartColor>
            <FromPartCount><xsl:value-of select="FromPartCount"/></FromPartCount>
            <FromPartPurpose><xsl:value-of select="FromPartPurpose"/></FromPartPurpose>
            <FromPartPartTypeName><xsl:value-of select="FromPartPartTypeName"/></FromPartPartTypeName>
            <!-- Include ToPart details -->
            <ToPartName><xsl:value-of select="ToPartName"/></ToPartName>
            <!-- Additional FromPartLink details -->
            <ToPartColor><xsl:value-of select="ToPartColor"/></ToPartColor>
            <ToPartCount><xsl:value-of select="ToPartCount"/></ToPartCount>
            <ToPartPurpose><xsl:value-of select="ToPartPurposes"/></ToPartPurpose>
            <ToPartPartTypeName><xsl:value-of select="ToPartPartTypeName"/></ToPartPartTypeName>
        </PartLink>
    </xsl:template>

    <!-- Template for each PartLink when going to this Part -->
    <xsl:template match="PartLink" mode="to">
        <PartLink  json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Description><xsl:value-of select="Description"/></Description>
            <PinNumber><xsl:value-of select="PinNumber"/></PinNumber>
            <!-- Include ToPart details -->
            <ToPartName><xsl:value-of select="ToPartName"/></ToPartName>
            <!-- Additional FromPartLink details -->
            <ToPartColor><xsl:value-of select="ToPartColor"/></ToPartColor>
            <ToPartCount><xsl:value-of select="ToPartCount"/></ToPartCount>
            <ToPartPurpose><xsl:value-of select="ToPartPurposes"/></ToPartPurpose>
            <ToPartPartTypeName><xsl:value-of select="ToPartPartTypeName"/></ToPartPartTypeName>
            <FromPartName><xsl:value-of select="FromPartName"/></FromPartName>
            <!-- Additional ToPartLink details -->
            <FromPartColor><xsl:value-of select="FromPartColor"/></FromPartColor>
            <FromPartCount><xsl:value-of select="FromPartCount"/></FromPartCount>
            <FromPartPurpose><xsl:value-of select="FromPartPurpose"/></FromPartPurpose>
            <FromPartPartTypeName><xsl:value-of select="FromPartPartTypeName"/></FromPartPartTypeName>
            <LowerVariableName><xsl:value-of select="LowerVairableName"/></LowerVariableName>
        </PartLink>
    </xsl:template>

    <xsl:template match="PartLinks">
        <PartLinks>
            <xsl:for-each select="PartLink">
                <xsl:sort select="Name" />
                <xsl:apply-templates select="." />
            </xsl:for-each>
        </PartLinks>
    </xsl:template>

    <!-- Template for each PartLink -->
    <xsl:template match="PartLink">
        <PartLink json:Array="true">
            <Name><xsl:value-of select="Name"/></Name>
            <Index><xsl:value-of select="Index"/></Index>
            <Description><xsl:value-of select="Description"/></Description>
            <FromPartPartTypeName><xsl:value-of select="FromPartPartTypeName"/></FromPartPartTypeName>
            <FromPartPurpose><xsl:value-of select="FromPartPurpose"/></FromPartPurpose>
            <ToPartName><xsl:value-of select="ToPartName"/></ToPartName>
            <ToPartColor><xsl:value-of select="ToPartColor"/></ToPartColor>
            <ToPartCount><xsl:value-of select="ToPartCount"/></ToPartCount>
            <ToPartPurpose><xsl:value-of select="ToPartPurposes"/></ToPartPurpose>
            <ToPartPartTypeName><xsl:value-of select="ToPartPartTypeName"/></ToPartPartTypeName>
            <LowerVariableName><xsl:value-of select="LowerVairableName"/></LowerVariableName>
            <!-- Additional PartLink details can be listed here -->
        </PartLink>
    </xsl:template>

</xsl:stylesheet>