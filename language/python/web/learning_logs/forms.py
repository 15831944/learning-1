from django import forms

from .models import Topic, Entry
from pydoc_data import topics

class TopicForm(forms.ModelForm):
    class Meta:
        model = Topic
        fields = ['text']
        loadls = {'text': ''}

class EntryForm(forms.ModelForm):
    class Meta:
        model = Entry
        fields = ['text']
        labels = {'text': ' '}
        widgets = {'text': forms.Textarea(attrs = {'cols': 80})}