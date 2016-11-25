namespace WindowsFormsApplication6
{
    partial class CreateEVolumeDialog
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.TotalSizeLabel = new System.Windows.Forms.Label();
            this.TotalSizeTextBox = new System.Windows.Forms.TextBox();
            this.PassphraseLabel = new System.Windows.Forms.Label();
            this.LocationLabel = new System.Windows.Forms.Label();
            this.Create = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.GBSizeType = new System.Windows.Forms.RadioButton();
            this.TBSizeType = new System.Windows.Forms.RadioButton();
            this.MBSizeType = new System.Windows.Forms.RadioButton();
            this.Cancel = new System.Windows.Forms.Button();
            this.PassphraseTextBox = new System.Windows.Forms.TextBox();
            this.eVolumeLocationTextBox = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // TotalSizeLabel
            // 
            this.TotalSizeLabel.AutoSize = true;
            this.TotalSizeLabel.Location = new System.Drawing.Point(18, 48);
            this.TotalSizeLabel.Name = "TotalSizeLabel";
            this.TotalSizeLabel.Size = new System.Drawing.Size(79, 20);
            this.TotalSizeLabel.TabIndex = 2;
            this.TotalSizeLabel.Text = "Total Size";
            // 
            // TotalSizeTextBox
            // 
            this.TotalSizeTextBox.Location = new System.Drawing.Point(114, 42);
            this.TotalSizeTextBox.Name = "TotalSizeTextBox";
            this.TotalSizeTextBox.Size = new System.Drawing.Size(100, 26);
            this.TotalSizeTextBox.TabIndex = 4;
            // 
            // PassphraseLabel
            // 
            this.PassphraseLabel.AutoSize = true;
            this.PassphraseLabel.Location = new System.Drawing.Point(289, 57);
            this.PassphraseLabel.Name = "PassphraseLabel";
            this.PassphraseLabel.Size = new System.Drawing.Size(93, 20);
            this.PassphraseLabel.TabIndex = 5;
            this.PassphraseLabel.Text = "Passphrase";
            // 
            // LocationLabel
            // 
            this.LocationLabel.AutoSize = true;
            this.LocationLabel.Location = new System.Drawing.Point(289, 138);
            this.LocationLabel.Name = "LocationLabel";
            this.LocationLabel.Size = new System.Drawing.Size(70, 20);
            this.LocationLabel.TabIndex = 6;
            this.LocationLabel.Text = "Location";
            // 
            // Create
            // 
            this.Create.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.Create.Location = new System.Drawing.Point(293, 344);
            this.Create.Name = "Create";
            this.Create.Size = new System.Drawing.Size(75, 38);
            this.Create.TabIndex = 8;
            this.Create.Text = "Create";
            this.Create.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.TotalSizeLabel);
            this.groupBox1.Controls.Add(this.TotalSizeTextBox);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(240, 370);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Volume Size";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.GBSizeType);
            this.groupBox2.Controls.Add(this.TBSizeType);
            this.groupBox2.Controls.Add(this.MBSizeType);
            this.groupBox2.Location = new System.Drawing.Point(22, 126);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(177, 159);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Size Type";
            // 
            // GBSizeType
            // 
            this.GBSizeType.AutoSize = true;
            this.GBSizeType.Location = new System.Drawing.Point(30, 82);
            this.GBSizeType.Name = "GBSizeType";
            this.GBSizeType.Size = new System.Drawing.Size(58, 24);
            this.GBSizeType.TabIndex = 6;
            this.GBSizeType.TabStop = true;
            this.GBSizeType.Text = "GB";
            this.GBSizeType.UseVisualStyleBackColor = true;
            // 
            // TBSizeType
            // 
            this.TBSizeType.AutoSize = true;
            this.TBSizeType.Location = new System.Drawing.Point(30, 113);
            this.TBSizeType.Name = "TBSizeType";
            this.TBSizeType.Size = new System.Drawing.Size(54, 24);
            this.TBSizeType.TabIndex = 7;
            this.TBSizeType.TabStop = true;
            this.TBSizeType.Text = "TB";
            this.TBSizeType.UseVisualStyleBackColor = true;
            // 
            // MBSizeType
            // 
            this.MBSizeType.AutoSize = true;
            this.MBSizeType.Location = new System.Drawing.Point(30, 52);
            this.MBSizeType.Name = "MBSizeType";
            this.MBSizeType.Size = new System.Drawing.Size(58, 24);
            this.MBSizeType.TabIndex = 5;
            this.MBSizeType.TabStop = true;
            this.MBSizeType.Text = "MB";
            this.MBSizeType.UseVisualStyleBackColor = true;
            // 
            // Cancel
            // 
            this.Cancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.Cancel.Location = new System.Drawing.Point(452, 344);
            this.Cancel.Name = "Cancel";
            this.Cancel.Size = new System.Drawing.Size(75, 38);
            this.Cancel.TabIndex = 10;
            this.Cancel.Text = "Cancel";
            this.Cancel.UseVisualStyleBackColor = true;
            // 
            // PassphraseTextBox
            // 
            this.PassphraseTextBox.Location = new System.Drawing.Point(427, 51);
            this.PassphraseTextBox.Name = "PassphraseTextBox";
            this.PassphraseTextBox.Size = new System.Drawing.Size(100, 26);
            this.PassphraseTextBox.TabIndex = 11;
            // 
            // eVolumeLocationTextBox
            // 
            this.eVolumeLocationTextBox.Location = new System.Drawing.Point(427, 132);
            this.eVolumeLocationTextBox.Name = "eVolumeLocationTextBox";
            this.eVolumeLocationTextBox.Size = new System.Drawing.Size(100, 26);
            this.eVolumeLocationTextBox.TabIndex = 12;
            // 
            // CreateEVolumeDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(555, 410);
            this.Controls.Add(this.eVolumeLocationTextBox);
            this.Controls.Add(this.PassphraseTextBox);
            this.Controls.Add(this.Cancel);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Create);
            this.Controls.Add(this.LocationLabel);
            this.Controls.Add(this.PassphraseLabel);
            this.Name = "CreateEVolumeDialog";
            this.Text = "Create Volume";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

       // private System.Windows.Forms.TextBox eVolumeLocation;
       // private System.Windows.Forms.TextBox Passphrase;
        private System.Windows.Forms.Label TotalSizeLabel;
        private System.Windows.Forms.TextBox TotalSizeTextBox;
        private System.Windows.Forms.Label PassphraseLabel;
        private System.Windows.Forms.Label LocationLabel;
        private System.Windows.Forms.Button Create;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton TBSizeType;
        private System.Windows.Forms.RadioButton GBSizeType;
        private System.Windows.Forms.RadioButton MBSizeType;
        private System.Windows.Forms.Button Cancel;
        private System.Windows.Forms.TextBox PassphraseTextBox;
        private System.Windows.Forms.TextBox eVolumeLocationTextBox;
    }
}